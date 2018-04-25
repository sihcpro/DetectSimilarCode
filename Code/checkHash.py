import sys
import pickle

listFileName = 'ls.txt'
folderInput = 'Result'

arrayHashing= []
arrayFileName= []

with open( listFileName ) as f:
	for line in f:
		fileName= line[:-1]
		arrayFileName.append( fileName )

for fileName in arrayFileName:
	# line = f.readline()
	hashing= pickle.load( open( folderInput+'/'+fileName, 'rb' ) )
	for i in range( len( arrayHashing ) ):
		bothHashing= arrayHashing[i].copy()
		bothHashing.update( hashing )

		percentX= len( hashing )         / len( bothHashing )
		percentY= len( arrayHashing[i] ) / len( bothHashing )

		if( len( arrayFileName ) > 10 ):
			if( max( percentX, percentY) > 0.9 ):
				print( "file %15s has %7s & %7s same file %15s" % ( fileName, str(round(percentX*100, 2))+'%', str(round(percentY*100, 2))+'%', arrayFileName[i] ) )
		else:
			print( "file %15s has %7s & %7s same file %15s" % ( fileName, str(round(percentX*100, 2))+'%', str(round(percentY*100, 2))+'%', arrayFileName[i] ) )

	arrayHashing.append( hashing )
	# print( hashing )
	# input()

