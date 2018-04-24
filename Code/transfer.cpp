#include <string>
#include <fstream>
#include <map>
#include <vector>
#include <iostream>
#include <unistd.h>

using namespace std;

#define PB( a ) push_back( (a) )

string fileName = "CFake1.cpp";
string folderInput = "Compile";
string folderOutput= "Transfer";
string contents= "";

map<string, int> typeData;
string data[35];
void initTypeData(){
	typeData["const"]	= 1;
	typeData["static"]	= 2;

	typeData["signed"]	= 6;
	typeData["unsigned"]= 7;

	typeData["long"]	= 10;
	typeData["short"]	= 11;

	typeData["int"]		= 12;
	typeData["void"]	= 13;
	typeData["bool"]	= 14;
	typeData["char"]	= 15;
	typeData["float"]	= 16;
	typeData["double"]	= 17;
	typeData["string"]	= 18;
	typeData["wchar_t"]	= 19;

	typeData["map"]				= 20;
	typeData["set"]				= 21;
	typeData["queue"]			= 22;
	typeData["stack"]			= 23;
	typeData["tuple"]			= 24;
	typeData["vector"]			= 25;
	typeData["multiset"]		= 26;
	typeData["unordered_map"]	= 27;
	typeData["unordered_set"]	= 28;
	typeData["priority_queue"]	= 29;

	// typeData["class"]	= 30;
	// typeData["struct"]	= 31;

	for(map<string, int>::iterator i= typeData.begin(); i != typeData.end(); i++){
		data[i->second] = i->first;
	}
	data[12]= "long";
}


void getContent(){
	string line;
	ifstream fin ((folderInput+"/"+fileName).c_str(), ifstream::in);
	// cout << "Example/"+fileName << endl;
	while( !fin.eof() ){
		getline( fin, line);
		contents+= line + '\n';
	}
	fin.close();
}
void skipSpace(string &str, int &n){
	while( str[n] == ' ' ) n++;
}

int getLengUntil(string &str, int start_pos, char c_end, char c_start = '\0'){
	int length= 1, count= 1;
	while( count > 0 ){
		if( str[ start_pos+length ] == c_end   )	count--;
		if( str[ start_pos+length ] == c_start )	count++;
		length++;
	}
	return length;
}
int getLengInclude(string &str, int start_pos){
	return getLengUntil( str, start_pos, '>', '<');
}
int getLengLine(string &str, int start_pos){
	int length= 1;
	while( str[start_pos+length] != '\n' )
		length++;
	return length;

}
int getLengNameVar(string &str, int start_pos){
	int length= 0;
	char c= tolower( str[start_pos+length] );
	if( '0' <= c && c <= '9' )	return 0;		// Exception number before name
	while( ( 'a' <= c && c <= 'z' ) || ( '0' <= c && c <= '9' ) || c == '_' ) {
		length++;
		c= tolower( str[start_pos+length] );
	}
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
string getNameVar(string &str, int start_pos){
	return str.substr(start_pos, getLengNameVar(str, start_pos));
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
	int length= 0;
	while( str[start_pos+length-1] != ';' )
		length++;
	return str.substr( start_pos, length);
}
string getGroupString(string &str, int start_pos){
	string result= "";
	while( start_pos < str.length() && str[start_pos-1] != ';' && str[start_pos-1] != '{' )
		result.PB(str[start_pos++]);
	return result;
}

void removeNext(string &str, int n, char target){
	while( str[n] != target )	n++;
	str[n]= ' ';
}



bool checkContinue(char &c1, char &c2){
	return ( c2 != ',' && c2 != ';');
}

bool checkEnd(char &c1, char &c2){
	return ( c1 != ')' && c2 != ';');
}




int findDataType(string &str, int &start_pos, string &s1){
	if( typeData.find( s1 ) == typeData.end() )
		return 0;
	int type= typeData[s1];
	// cout << "s1 ========== " << s1 << endl;
	start_pos+= s1.length();
	switch( type/10 ){
		case 0:
			// start_pos+= s1.length();
			skipSpace(str, start_pos);
			s1= getNameVar(str, start_pos);
			// start_pos+= s1.length();
			return findDataType(str, start_pos, s1);
		case 1:
			// start_pos+= s1.length();
			if( type < 12 ){
				skipSpace(str, start_pos);
				string s2 = getNameVar(str, start_pos);
				// start_pos+= s2.length();
				// cout << s1 << " -> " << s2 << " = " << type << endl;
				int type2 = findDataType(str, start_pos, s2);
					// start_pos-= s2.length();
				if( type2 == 0 ){
					return type;
				}
				else{
					return type2;
				}
			}
			else
				return type;
		case 2:
				skipSpace( str, start_pos);
				start_pos+= getLengInclude(str, start_pos);
		case 3:
			return type;			
	}
}



void deleteParenthesis(string &str, int start_pos){
	int deep= 1;
	while( deep ){
		switch( str[start_pos] ){
			case '(':	
				deep++;	
				str[start_pos++]=' ';	break;
			case ')':	
				deep--;	
				if( deep == 0 )			return;		
				str[start_pos++]=' ';	break;
			case ';':					return;
			default:start_pos++;
		}
	}
}
string sp;
string getNameVarSkipSymbol(string &str, int &start_pos){
	while( getLengNameVar(contents, start_pos) == 0 )
		start_pos++;
	sp= getNameVar(contents, start_pos);
	start_pos+= sp.length();
	return sp;
}
void variableNormal(string &str, int &start_pos, map<string, int> &m, int type){
	deleteParenthesis(str, start_pos);
	skipSpace(str, start_pos);
	while( str[start_pos] != ',' && str[start_pos] != ';' )
		start_pos++;
	while( str[start_pos] != ';' ){
		sp= getNameVarSkipSymbol(contents, start_pos);
		// cout << sp.length() << endl;
		// start_pos+= sp.length();
		// cout << "variable = " << sp << "  type = " << data[type] << endl;
		m[sp]= type;
		while( str[start_pos] != ',' && str[start_pos] != ';' )
			start_pos++;
	}
	start_pos++;
}
void getVariable(string &str, int &start_pos, map<string, int> &m){
	while( getLengNameVar(contents, start_pos) == 0 )
		start_pos++;
	string s1= getNameVar(contents, start_pos);
	int type= findDataType( contents, start_pos, s1);
	sp= getNameVarSkipSymbol(contents, start_pos);
	// cout << s1 << "(" << data[type] << ")" << " : [" << sp << "]("<<sp.length()<<")\n";
	m[sp]= type;
}
void variableInFunc(string &str, int &start_pos, map<string, int> &m){
	// We have 2 case: have no variable or more than one

	deleteParenthesis(str, start_pos+1);
	start_pos++;
	skipSpace(str, start_pos);
	if( str[start_pos] == ')' )		return;

	getVariable(contents, start_pos, m);
	while( str[start_pos] != ',' && str[start_pos] != ')' )
		start_pos++;



	while( str[start_pos] != ')' ){
		start_pos++;
		// Tien xu li
		// sp= getNameVar(contents, start_pos);
		// cout << " now in fuct has sp = " << sp << " at " << start_pos<< endl;
		// if( sp.length() == 0 ){
		// 	while( str[start_pos] != ',' && str[start_pos] != ')' )
		// 		start_pos++;
		// 	if( str[start_pos] == ')' )		return;
		// 	// if( start_pos ==  )
		// 	start_pos++;

		// 	sp= getNameVar(contents, start_pos);
		// 	while( sp.length() == 0 )
		// 		sp= getNameVar(contents, ++start_pos);
		// // }

		// int type= findDataType( contents, start_pos, sp);
		// // start_pos+= data[type].length();

		// if( type/ 10 == 2 ){
		// 	skipSpace( contents, start_pos);
		// 	start_pos+= getLengInclude(contents, start_pos);
		// }
		// sp= getNameVar(contents, start_pos);
		// while( sp.length() == 0 )
		// 	sp= getNameVar(contents, ++start_pos);
		// // cout << sp.length() << endl;
		// start_pos+= sp.length();
		// cout << "variable = " << sp << "  type = " << data[type] << endl;
		// m[sp]= type;
		getVariable(contents, start_pos, m);
		while( str[start_pos] != ',' && str[start_pos] != ')' )
			start_pos++;
	}
}







vector< map< string, int> > vec;
int line= 1, deep= 0;
bool error= false;

void inside(string &result, int &n){
	map<string, int> variable;
	string s1, s2, s3, s4;

	long m= n-1;
	while( n < contents.length() && !error ){
		if( m == n ){
			cout << "Stop at line : " << line << " !\n";
			error= true;
			return;
		}
		m= n;

		// cout << n << " [" << contents[n] << "] -> ";
		while( n < contents.length() && ( contents[n] == ' ' || contents[n] == '\t' ) ) n++;
		if( n == contents.length() )
			break;
		// cout << n << " [" << contents[n] << "] is ";
		char c= tolower(contents[n]);
		// cout << "[" << c << "]" <<"\n";
		if( ( c < 'a' || c > 'z' ) && c != '_' ){	// symbol
			switch( c ){
				case '#':
					n+= getLengLine( contents, n)+1;
					line++;
					continue;
				// case ';':
				// 	n++;
				// 	result.PB( '\n' );
				// 	continue;
				// case '<':
				// 	if( contents[n+1] != '<' )
				// 		n+= getLengUntil( contents, n, '>', '<');
				// 	else{
				// 		result+= "<<";
				// 		n+= 2;
				// 	}
				// 	continue;
				case '{':
					vec.PB(variable);
					result.PB(contents[n]);
					deep++;
					inside(result, ++n);
					continue;
				case '}':
					// vec.pop_back();
					result.PB(contents[n]);
					n++;
					deep--;
					// cout << "I'm out\n";
					return;
				case '"':
					result.PB(contents[n++]);
					while( contents[n] != '"' )
						result.PB( tolower(contents[n++]) );
					result.PB(contents[n++]);
					continue;
				case '\'':
					result.PB(contents[n++]);
					while( contents[n] != '\'' )
						result.PB( tolower(contents[n++]) );
					result.PB(contents[n++]);
					continue;
				case '\n':
					line++;
					n++;
					continue;
				default: 
					// cout << contents[n] << endl;
					result.PB(contents[n]);
					n++;
					continue;
			}
		} else {
			s1= getNameVar( contents, n);
			// cout << s1 << endl;
			int type;
			if( typeData.find( s1 ) != typeData.end() ){
				// cout << "found : " << s1 << " at: " << n << endl;
				type= findDataType( contents, n, s1);
				// cout << type << " = " + data[type] << endl;
				// n+= data[type].length();

				// if( type/ 10 == 2 ){
				// 	skipSpace( contents, n);
				// 	n+= getLengInclude(contents, n);
				// }
				s2= getNameVar(contents, n);
				
				while( s2.length() == 0 ){
					if( contents[n] == ')' )	break;
					if( contents[n] == '(' ){
						contents[n]= ' ';
						removeNext(contents, n, ')');
					}
					s2= getNameVar(contents, ++n);
				}
				if( contents[n] == ')' )	continue;

				// cout << "variable = " << s2 << "  type = " << data[type] << endl;
				variable[s2]= type;
				n+= s2.length();
				skipSpace(contents, n);
				// cout << "hhhhhhhhhhhhhhhherer = " << contents[n] << endl;
				if( contents[n] == ')' ){
					result+= s2;
					continue;
				}
				else if( contents[n] == '(' ){
					result+= s1+'(';
					// cout << "--------------------\n";
					variableInFunc( contents, n, variable);
				}
				else{
					variableNormal( contents, n, variable, type );				
				}
			}
			else if( s1.length() > 0 ){
				s2= s1;
				if( variable.find( s1 ) != variable.end() )
					s2= data[ variable[s1] ];
				else for( int i= vec.size()-1; i >= 0; i--){
					if( vec[i].find( s1 ) != vec[i].end() ){
						s2= data[ vec[i][s1] ];
						break;
					}
				}
				result = result + s2;
				// cout << "[" + s1 + "](" << result.length() << ")" << endl;
				n+= s1.length();
			}

			if( s1.length() == 0 ){
				cout << "error\n";
				n++;
			}
		}
		// cout << s1 << " n= " << n << " line= " << line << "  deep = " << deep << endl;

	}
}

int main(int argc, char** argv){
	switch( argc ){
		case 1:
			cout << "Warning no file name input in Transfer!\n";
			break;
		case 4:
			folderOutput = argv[3];
		case 3:
			folderInput = argv[2];
		case 2:
			fileName = argv[1];
	}
	getContent();
	initTypeData();

	for(int i, j;false;);

	string result= "";
	int n= 0, bracket= 0, type;
	map<string, string> variable;

	inside( result, n );

	ofstream fout ((folderOutput+"/"+fileName).c_str(), ios::out | ios::trunc );
	// cout << contents << endl;
	// cout << "-----------------------------------------------------------------------\n";
	// cout << result << endl;
	fout << (string)result;
	fout.close();
	return 0;
}
