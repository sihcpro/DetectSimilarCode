from itertools import groupby
from operator import itemgetter
import sys
import pickle

listFileName = 'ls.txt'
folderInput = 'Result'

if len( sys.argv ) >= 2:
	listFileName = sys.argv[1]
if len( sys.argv ) >= 3:
	folderInput = sys.argv[2]

def longest_common_substring(text):
    """Get the longest common substrings and their positions.
    >>> longest_common_substring('banana')
    {'ana': [1, 3]}
    >>> text = "not so Agamemnon, who spoke fiercely to "
    >>> sorted(longest_common_substring(text).items())
    [(' s', [3, 21]), ('no', [0, 13]), ('o ', [5, 20, 38])]

    This function can be easy modified for any criteria, e.g. for searching ten
    longest non overlapping repeated substrings.
    """
    sa, rsa, lcp = suffix_array(text)
    maxlen = max(lcp)
    result = {}
    for i in range(1, len(text)):
        if lcp[i] == maxlen:
            j1, j2, h = sa[i - 1], sa[i], lcp[i]
            assert text[j1:j1 + h] == text[j2:j2 + h]
            substring = text[j1:j1 + h]
            if not substring in result:
                result[substring] = [j1]
            result[substring].append(j2)
    return dict((k, sorted(v)) for k, v in result.items())

def suffix_array(text, _step=16):
    """Analyze all common strings in the text.

    Short substrings of the length _step a are first pre-sorted. The are the 
    results repeatedly merged so that the garanteed number of compared
    characters bytes is doubled in every iteration until all substrings are
    sorted exactly.

    Arguments:
        text:  The text to be analyzed.
        _step: Is only for optimization and testing. It is the optimal length
               of substrings used for initial pre-sorting. The bigger value is
               faster if there is enough memory. Memory requirements are
               approximately (estimate for 32 bit Python 3.3):
                   len(text) * (29 + (_size + 20 if _size > 2 else 0)) + 1MB

    Return value:      (tuple)
      (sa, rsa, lcp)
        sa:  Suffix array                  for i in range(1, size):
               assert text[sa[i-1]:] < text[sa[i]:]
        rsa: Reverse suffix array          for i in range(size):
               assert rsa[sa[i]] == i
        lcp: Longest common prefix         for i in range(1, size):
               assert text[sa[i-1]:sa[i-1]+lcp[i]] == text[sa[i]:sa[i]+lcp[i]]
               if sa[i-1] + lcp[i] < len(text):
                   assert text[sa[i-1] + lcp[i]] < text[sa[i] + lcp[i]]
    >>> suffix_array(text='banana')
    ([5, 3, 1, 0, 4, 2], [3, 2, 5, 1, 4, 0], [0, 1, 3, 0, 0, 2])

    Explanation: 'a' < 'ana' < 'anana' < 'banana' < 'na' < 'nana'
    The Longest Common String is 'ana': lcp[2] == 3 == len('ana')
    It is between  tx[sa[1]:] == 'ana' < 'anana' == tx[sa[2]:]
    """
    tx = text
    size = len(tx)
    step = min(max(_step, 1), len(tx))
    sa = list(range(len(tx)))
    sa.sort(key=lambda i: tx[i:i + step])
    grpstart = size * [False] + [True]  # a boolean map for iteration speedup.
    # It helps to skip yet resolved values. The last value True is a sentinel.
    rsa = size * [None]
    stgrp, igrp = '', 0
    for i, pos in enumerate(sa):
        st = tx[pos:pos + step]
        if st != stgrp:
            grpstart[igrp] = (igrp < i - 1)
            stgrp = st
            igrp = i
        rsa[pos] = igrp
        sa[i] = pos
    grpstart[igrp] = (igrp < size - 1 or size == 0)
    while grpstart.index(True) < size:
        # assert step <= size
        nextgr = grpstart.index(True)
        while nextgr < size:
            igrp = nextgr
            nextgr = grpstart.index(True, igrp + 1)
            glist = []
            for ig in range(igrp, nextgr):
                pos = sa[ig]
                if rsa[pos] != igrp:
                    break
                newgr = rsa[pos + step] if pos + step < size else -1
                glist.append((newgr, pos))
            glist.sort()
            for ig, g in groupby(glist, key=itemgetter(0)):
                g = [x[1] for x in g]
                sa[igrp:igrp + len(g)] = g
                grpstart[igrp] = (len(g) > 1)
                for pos in g:
                    rsa[pos] = igrp
                igrp += len(g)
        step *= 2
    del grpstart
    # create LCP array
    lcp = size * [None]
    h = 0
    for i in range(size):
        if rsa[i] > 0:
            j = sa[rsa[i] - 1]
            while i != size - h and j != size - h and tx[i + h] == tx[j + h]:
                h += 1
            lcp[rsa[i]] = h
            if h > 0:
                h -= 1
    if size > 0:
        lcp[0] = 0
    return sa, rsa, lcp

def winnow(w, hashing):
	Min = hashing[0]
	vt = 0
	for i in range (0, w):
		if (hashing[i] <= Min): 
			Min = hashing[i]
			vt = i
	fingerprint = [Min]
	fingerprintVT = [vt]
	for i in range(w, len(hashing)):
		new = False
		if (vt <= i-w) :
			vt = i-w+1
			Min = hashing[vt]
			for j in range(i-w+1, i+1):
				if (hashing[j] <= Min): 
					Min = hashing[j]
					vt = j
					new = True
		else :
			if (hashing[i] <= Min):
				Min = hashing[i]
				vt = i
				new = True
		if (new):
			fingerprint.append(Min)
			fingerprintVT.append(vt)
	return fingerprint, fingerprintVT

arrayHashing= []
arrayFileName= []

with open( listFileName ) as f:
	for line in f:
		fileName= line[:-1]
		arrayFileName.append( fileName )

for fileName in arrayFileName:
	# line = f.readline()
	hashingA = pickle.load( open( folderInput+'/'+fileName, 'rb' ) )
	lenA = len( hashingA )
	hashingA.append(0);
	for p in range( len( arrayHashing ) ):
		hashingB = arrayHashing[p].copy()
		lenB = len( hashingB )

		bothHashing = hashingA + hashingB
		lenBoth = len(bothHashing)

		sa, rsa, lcp = suffix_array(bothHashing)

		l = 0
		r = 0

		chepA = []
		chepB = []

		for i in range(2, lenBoth ):
			if (lcp[i] >= 5):
				if (l == 0): 
					l = i-1
					r = i
				else :
					r+=1
			else :
				if (l == 0): 
					continue
				yesA = False
				yesB = False
				for j in range(l, r+1) : 
					if (sa[j] < lenA) : 
						yesA = True
					else : 
						yesB = True
				if (yesA and yesB) :
					for j in range(l, r+1) : 
						if (sa[j] < lenA) : 
							chepA.append(sa[j])
						else : 
							chepB.append(sa[j] - 1 - lenA)
				l = 0
				r = 0

		if (l > 0):
			yesA = False
			yesB = False
			for j in range(l, r+1) : 
				if (sa[j] < lenA) : 
					yesA = True
				else : 
					yesB = True
			if (yesA and yesB) :
				for j in range(l, r+1) : 
					if (sa[j] < lenA) : 
						chepA.append(sa[j])
					else : 
						chepB.append(sa[j] - 1 - lenA)

		rA = [0 for i in range(lenA)]
		rB = [0 for i in range(lenB - 1)]

		for i in range( len(chepA) ):
			# print(chepA[i])
			for j in range(5):
				if (chepA[i] + j >= len(rA)): 
					continue
				rA[chepA[i]+j] += 1

		for i in range( len(chepB) ):
			for j in range(5):
				if (chepB[i] + j >= len(rB)): 
					continue
				rB[chepB[i]+j] += 1

		g = 0
		h = 0
		for i in range( len(rA) ):
			if (rA[i] >= 1): 
				# print(i)
				g += 1


		# print(g)
		# print(len(rA))

		for i in range( len(rB) ):
			if (rB[i] >= 1): 
				h += 1

		percentX= g / len(rA)
		percentY= h / len(rB)

		if( max( percentX, percentX) >= 0.8 ):
			print( "file %15s has %7s & %7s same file %15s" % ( fileName, str(round(percentX*100, 2))+'%', str(round(percentY*100, 2))+'%', arrayFileName[p] ) )

		# print( "lenA = %s | lenB = %s | both = %s" % (lenA, lenB, len( bothHashing ) ) )
		

	arrayHashing.append( hashingA )
	# print( hashing )
	# input()

