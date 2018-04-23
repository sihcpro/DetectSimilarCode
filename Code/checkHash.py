import sys
import pickle

listFileName = 'ls.txt'
folderInput = 'Result'

arrayHashing= []
arrayFileName= []

with open( listFileName ) as f:
	for line in f:
		# line = f.readline()
		fileName= line[:-1]
		hashing= pickle.load( open( folderInput+'/'+fileName, 'rb' ) )
		for i in range( len( arrayHashing ) ):
			bothHashing= arrayHashing[i].copy()
			bothHashing.update( hashing )

			percentX= len( hashing )         / len( bothHashing )
			percentY= len( arrayHashing[i] ) / len( bothHashing )

			if( max( percentX, percentY) > 0.9 ):
				print( "file "+fileName+" has "+str(percentX)+" & "+str(percentY)+" same file "+arrayFileName[i] )

		arrayHashing.append( hashing )
		arrayFileName.append( fileName )
		# print( hashing )
		# input()

