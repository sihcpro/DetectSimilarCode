#include <string>
#include <fstream>
#include <iostream>

using namespace std;

#define PB( a ) push_back( (a) )

string fileName = "main09.cpp";
string folderInput = "Example";
string folderOutput= "Process";
string contents= "";

void getContent(){
	string line;
	ifstream fin ((folderInput+"/"+fileName).c_str(), ifstream::in);
	while( !fin.eof() ){
		getline( fin, line);
		contents+= line + '\n';
	}
	fin.close();
}

int getLengInclude(string &str, int start_pos){
	int length= 1;
	while( str[start_pos+length] != '>' )
		length++;
	return length+1;
}
int getLengLine(string &str, int start_pos){
	int length= 1;
	while( str[start_pos+length] != '\n' )
		length++;
	return length;

}
int getLengSemiColon(string &str, int start_pos){
	int length= 1;
	while( str[start_pos+length-1] != ';' )
		length++;
	return length;

}
string getOnlyString(string &str, int start_pos){
	char c= tolower( str[start_pos] );
	string result= "";
	while( 'a' <= c && c <= 'z' ){
		result.PB( str[start_pos++] );
		c= tolower( str[start_pos] );
	}
	return result;
}
string getString(string &str, int start_pos){
	char c= tolower( str[start_pos] );
	string result= "";
	while( ( 'a' <= c && c <= 'z' ) || ( '0' <= c && c <= '9' ) ) {
		result.PB( str[start_pos++] );
		c= tolower( str[start_pos] );
	}
	return result;
}
string getSemiColon(string &str, int start_pos){
	string result= "";
	while( str[start_pos-1] != ';' )
		result.PB(str[start_pos++]);
	return result;
}

int main(int argc, char** argv){
	switch( argc ){
		case 1:
			cout << "Warning no file name input in Process!\n";
			break;
		case 4:
			folderOutput = argv[3];
		case 3:
			folderInput = argv[2];
		case 2:
			fileName = argv[1];
	}
	getContent();

	ofstream fout ((folderOutput+"/"+fileName).c_str(), ios::out | ios::trunc );

	int n= 0;

	while( n < contents.length() ){
		switch( contents[n] ){
			case '#':	// Skip include
				if( getOnlyString(contents, n+1).compare( "include" ) == 0 )
					n+= getLengInclude(contents, n);
				break;
			case 'u':	// Skip using namespace
				if( getOnlyString( contents, n).compare( "using" ) == 0 )
					n+= getLengLine( contents, n);
				break;
			case 't':	// Skip typedef
				if( getOnlyString( contents, n).compare( "typedef" ) == 0 ){
					string s1, s2= "", s3= "";
					s1= getSemiColon(contents, n+7);
					int i= 0, j= s1.length()-1;
					n+= s1.length()+7;

					// O(n)
					while( s1[i] == ' ' ) i++;
					while( s1[j] == ' ' ) j--;	// space between semi-colon and word
					while( s1[j] != ' ' ) j--;

					for(; i <= j; i++)
						s2.PB( s1[i] );
					s3= getString(s1, j+1);
					fout << "#define " << s3 << " " << s2;
				}
				break;
			// case '/':	// Skip comment
			// 	if( n+1 < contents.length() && contents[n+1] == '/' )
			// 		n+= getLengLine( contents, n);
			// 	else if( n+1 < contents.length() && contents[n+1] == '*' ){
			// 		n++;
			// 		cout << "[" << contents[n] << n << "]" << endl;
			// 		while( !( n < contents.length() && contents[n-1] == '*' && contents[n] == '/' ) )
			// 			n++;
			// 		n++;
			// 	}
			// 	break;
			default: ;
		}
		if( n < contents.length () )
			fout << contents [ n++ ] ;
	}

	fout.close();
	return 0;
}
