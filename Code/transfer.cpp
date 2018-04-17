#include <string>
#include <fstream>
#include <map>
#include <iostream>

using namespace std;

#define PB( a ) push_back( (a) )

string fileName= "main01.cpp";
string contents= "";

map<string, int> typeData;
void initTypeData(){
	typeData["signed"]	= 0;
	typeData["unsigned"]= 1;

	typeData["short"]	= 2;
	typeData["long"]	= 3;

	typeData["bool"]	= 4;
	typeData["char"]	= 5;
	typeData["int"]		= 6;
	typeData["float"]	= 7;
	typeData["double"]	= 8;
	typeData["wchar_t"]	= 9;
	typeData["void"]	= 10;
}


void getContent(){
	string line;
	ifstream fin (("PreCompile/"+fileName).c_str(), ifstream::in);
	// cout << "Example/"+fileName << endl;
	while( !fin.eof() ){
		getline( fin, line);
		contents+= line + '\n';
	}
	fin.close();
}



int getLengInclude(string &str, int start_pos){
	int length= 1, count= 1;
	while( count > 0 ){
		if( str[ start_pos+length ] == '>' )	count--;
		if( str[ start_pos+length ] == '<' )	count++;
		length++;
	}
	return length;
}
int getLengLine(string &str, int start_pos){
	int length= 1;
	while( str[start_pos+length] != '\n' )
		length++;
	return length;

}
int getLengSemiColon(string &str, int start_pos){
	int length= 1;
	while( str[start_pos+length] != ';' )
		length++;
	return length+1;

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
string getLine(string &str, int start_pos){
	string result= "";
	while( str[start_pos] != '\n' )
		result.PB(str[start_pos++]);
	return result;
}
string getInBracket(string &str, int start_pos){
	string result= "";
	while( str[start_pos-1] != ')' )
		result.PB(str[start_pos++]);
	return result;
}
string getSemiColon(string &str, int start_pos){
	string result= "";
	while( str[start_pos-1] != ';' )
		result.PB(str[start_pos++]);
	return result;
}








class Type{
private:
	string variable, true_name, string_replace;
	bool have_variable;
public:
	Type(string string_define){
		string tmp;
		int n= 0;
		cout << "Type :" << string_define << endl;
		while( n < string_define.length() ){
			tmp = getString(string_define, n);
			cout << tmp << endl;
			n+= tmp.length();
			// cin >> tmp;
			// usleep(3000);
			n++;
		}
		// string 
	}
};








int main(){

	getContent();
	initTypeData();

	string result= "", s1, s2, s3, s4;
	int n= 0, bracket= 0, type;
	while( n < contents.length() ){
		if( contents[n] == '#' )	// Skip comment when compile
			n+= getLengLine(contents, n);
		else{
			if( bracket == 0 ){
				s1= getOnlyString( contents, n);
				type= typeData[s1];
				// if(  ){





				// }
			}

			result += contents[n];
			n++;


		}
	}

	ofstream fout (("Result/"+fileName).c_str(), ios::out | ios::trunc );
	fout << result;
	fout.close();
	return 0;
}