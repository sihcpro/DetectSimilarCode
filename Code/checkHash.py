from itertools import groupby
from operator import itemgetter
import sys
import pickle

listFileName= 'ls2.txt'
noisyLength = 5
folderInput = 'Hash'
folderOutput= 'Result'
folderTransfer= 'Transfer'

if len( sys.argv ) > 1:
	listFileName= sys.argv[1]
if len( sys.argv ) > 2:
	noisyLength = int( sys.argv[2] )
if len( sys.argv ) > 3:
	folderInput = sys.argv[3]
if len( sys.argv ) > 4:
	folderOutput= sys.argv[4]
if len( sys.argv ) > 5:
	folderTransfer= sys.argv[5]

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

def suffix_array(text, _step=2):
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
arrayHashingLen = []
arrayHashingFingerprintVT = []
arrayFileName= []

with open( listFileName ) as f:
	for line in f:
		fileName= line[:-1]
		arrayFileName.append( fileName )

for fileName in arrayFileName:
	# line = f.readline()
	hashingA = pickle.load( open( folderInput+'/'+fileName, 'rb' ) )
	lenAA = len(hashingA)

	hashingA, fingerprintVTA = winnow(5, hashingA)
	lenA = len( hashingA )

	hashingA.append(-1)
	samefile= []
	for p in range( len( arrayHashing ) ):
		hashingB = arrayHashing[p].copy()
		lenB = len( hashingB )
		hashingB.append(-2)
		lenBB = arrayHashingLen[p]
		fingerprintVTB = arrayHashingFingerprintVT[p].copy()

		bothHashing = hashingA + hashingB
		lenBoth = len(bothHashing)

		sa, rsa, lcp = suffix_array(bothHashing)

		l = 0
		r = 0

		chepA = []
		chepB = []

		for i in range(2, lenBoth ):
			if (lcp[i] >= 2):
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
						if (sa[j] < lenA ) :
							if (sa[j] + 1 < lenA) :  
								chepA.append((fingerprintVTA[sa[j]], fingerprintVTA[sa[j]+1]))
						else : 
							if (sa[j] - lenA < lenB) :
								chepB.append((fingerprintVTB[sa[j] - 1 - lenA], fingerprintVTB[sa[j] - lenA]))
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
					if (sa[j] < lenA ) :
						if (sa[j] + 1 < lenA) :  
							chepA.append((fingerprintVTA[sa[j]], fingerprintVTA[sa[j]+1]))
					else : 
						if (sa[j] - lenA < lenB) :
							chepB.append((fingerprintVTB[sa[j] - 1 - lenA], fingerprintVTB[sa[j] - lenA]))

		rA = [0 for i in range(lenAA)]
		rB = [0 for i in range(lenBB)]

		for i in range( len(chepA) ):
			for j in range(chepA[i][0], chepA[i][1]+1):
				rA[j] += 1

		for i in range( len(chepB) ):
			for j in range(chepB[i][0], chepB[i][1]+1):
				rB[j] += 1

		g = 0
		h = 0
		for i in range( len(rA) ):
			if (rA[i] >= 1): 
				g += 1

		# print(g)


		pos= [ i for i in range(len(rB)) ]
		for i in range( len(rB) ):
			if (rB[i] >= 1):
				# print(i)
				h += 1
				for j in range( noisyLength ):
					if i-j-1 > 0 and rB[i-j-1] >= 1:
						pos[i]= pos[i-j-1]
		# print(pos)


		ed= len(rB)-noisyLength-1
		arrayLengthCopy= []
		while( ed > 0 ):
			bg= pos[ed]
			if( ed-bg+1 > noisyLength ):
				arrayLengthCopy.append( [bg, ed] )
				ed= bg
			else:
				ed-= 1




		percentX= g / len(rA)
		percentY= h / len(rB)

		if( max( percentX, percentY) > 0.5 ):
			print( "file %15s has %7s & %7s same file %15s" % ( fileName, str(round(percentX*100, 2))+'%', str(round(percentY*100, 2))+'%', arrayFileName[p] ) )
			samefile.append( { 'filename': arrayFileName[p], 'percent': round( max( percentX, percentY)*100, 2 ), 'copy': arrayLengthCopy, 'line': []} )

		# print( "lenA = %s | lenB = %s | both = %s" % (lenA, lenB, len( bothHashing ) ) )
	if len( samefile ) > 0:
		numLine= 0
		l= 1
		for i in samefile:
			f2 = open( folderTransfer+'/'+i['filename'], 'r' )

			length= 0
			x= y= 0
			line= " "
			for j in reversed( i['copy'] ):

				while( line != '' ):
					print( "%s %3d %5d %s" % ( 'x', l, length, line ) , end= '')
					if( length > j[0] ):
						x= l
						break
					line = f2.readline()
					length+= len(line)-1
					l+= 1
				# print( "%s %3d %5d %s" % ( '-', l, length, line ) , end= '')
				while( line != '' ):
					print( "%s %3d %5d %s" % ( 'y', l, length, line ) , end= '')
					if( length > j[1] ):
						y= l
						break
					line = f2.readline()
					length+= len(line)-1
					l+= 1
				print( x, y)
				i['line'].append( [x,y] )

			contents= []
			while( line != '' ):
				line= f2.readline()
				contents.append( line )
				l+= 1
			l-= 1
			numLine= int( contents[-3] )
			# print( "normal have ", numLine, " line but in here we have ", l, " line")


		l-= 3
		f = open( folderOutput+'/'+fileName, "w" )
		f.write( str( len( samefile ) ) + '\n' )
		for i in samefile:
			f.write( i['filename'] + ' ' + str( i['percent'] ) + '\n' + str( len( i['copy'] ) ) + '\n'  )

			# for j in reversed( i['copy'] ):
			# 	f.write( str( j[0] ) + ' ' + str( j[1] ) + '\n' )
			for j in i['line']:
				f.write( str( numLine-l+j[0] ) + ' ' + str( numLine-l+j[1] ) + '\n' )
		f.close()


	hashingA = hashingA[:-1]
	arrayHashing.append( hashingA )
	arrayHashingLen.append(lenAA)
	arrayHashingFingerprintVT.append(fingerprintVTA)
	# print( hashing )
	# input()

