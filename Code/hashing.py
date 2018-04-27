import sys
import pickle

hashLength= 10
fileName= "main08.cpp"
folderInput = "Transfer"
folderOutput= "Hash"

if len( sys.argv ) >= 2:
	hashLength= int( sys.argv[1] )
if len( sys.argv ) >= 3:
	fileName= sys.argv[2]
if len( sys.argv ) >= 4:
	folderInput = sys.argv[3]
if len( sys.argv ) >= 5:
	folderOutput= sys.argv[4]

# print( hashLength, fileName, folderInput, folderOutput)

f = open( folderInput+'/'+fileName, "r" )
contents= ""
for line in f:
	contents+= line[:-1]

# print( contents )
f.close()

contents= list( map( ord, contents.upper() ) )
s= 0
skip= 31
space= 127 - skip - 26
m= 1

contents[0]= ord( '~' )
ss= ' '
for i in range( hashLength ):
	ss= chr( contents[i] )
	# print( ss, contents[i], " " );
	if contents[i] >= 123:
		contents[i]-= 26
	# print( chr( contents[i] ), " " );
	contents[i]-= skip
	s= s*space + contents[i]
	m*= space
	# print( contents[i] - skip, space, s )
m= space**(hashLength-1)

# print(s)
# print("------------------------")
hashing= [s]
for i in range( hashLength, len( contents ) ):
	# print( contents[i-hashLength], contents[i-hashLength] * m );
	# print( s );
	s-= ( contents[i-hashLength] * m )
	# print( s );
	s= s*space + contents[i]
	# z= input()
	hashing.append(s)

# for i,j in hashing.items():
# 	print( i, j)

# f = open( folderOutput+'/'+fileName, 'a')
# f.write( hashing )
pickle.dump(hashing, open( folderOutput+'/'+fileName, 'wb'))
