#include <bits/stdc++.h>
#include <unistd.h>

using namespace std;

#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define PI 3.14159265

//typedef tuple<int, int, int> t3;
typedef long long ll;
typedef unsigned long long ull;
typedef double db;
typedef long double ld;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
typedef pair <ll, int> pli;
typedef pair <db, db> pdd;

#define siz(x) (int)(x).size()
#define Se second
#define Fi first
#define IN insert
#define PB push_back
#define P pop_back
#define PU push
#define PO pop
#define F find
#define ED end()
#define MP( a, b) make_pair( a, b )

#define mod 1000000007ll
#define rep( bg, i, num ) for(ll (i)= (bg); (i) < (num); (i)++)
#define repd( num, i, ed ) for(ll (i)= (num)-1; (i) >= ed; (i)--)
#define repkt( bg, i, num, kt ) for(ll (i)= (bg); (i) < (num) && (kt); (i)++)
#define repchar( i ) for(char (i)= 48; (i) <= 122; (i)++)
#define in(n) scanf("%lld", &n)
#define out(n) printf("%lld\n", n)
#define outS(s) printf("%s\n", s)
#define setA(a,n) for(ll i= 0; i < sizeof(a); i++) a[i]= n;

typedef ll cap;
typedef priority_queue<cap> pqmax;
typedef priority_queue<cap, vector<cap>, greater<cap> > pqmin;

ll junger= 0, mid= 0, top= 0, bot= 0, result= 0, sum= 0, s= 0, t= 0, d= 0, l= 0, sp= 0, k= 0, x, y, n, m, test, r;
bool kt= false, t1= false, t2= false;
string s1, s2;




























string getOnlyString(string &str, int start_pos){
	char c= tolower( str[start_pos] );
	string result= "";
	while( 'a' <= c and c <= 'z' ){
		result.PB( str[start_pos++] );
		c= tolower( str[start_pos] );
	}
	return result;
}

int getInclude(string &str, int start_pos){
	int length= 1;
	while( str[start_pos+length] != '>' )
		length++;
	return length+1;
}

string getString(string &str, int start_pos){
	string result= "";
	while( !( str[start_pos] == ' ' || str[start_pos] == '\t' || str[start_pos] == '\n' ) )
		result.PB(str[start_pos++]);
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











class Define{
private:
	string variable, true_name, string_replace;
	bool have_variable;
public:
	Define(string string_define){
		string tmp;
		int n= 0;
		cout << "Define :" << string_define << endl;
		while( n < string_define.length() ){
			tmp = getString(string_define, n);
			cout << tmp << endl;
			n+= tmp.length();
			// cin >> tmp;
			usleep(3000);
			n++;
		}
	}
};

map< string, Define > mapDefine;















int main()
{
	string fileName= "main01";

	ifstream fin (("Example/"+fileName+".cpp").c_str(), ifstream::in);
	ofstream fout (("Result/"+fileName+".out").c_str(), ios::out | ios::trunc );

	// while( !fin.eof()  ){
	// 	// getline( fin, s1);
	// 	fin >> s1;
	// 	cout << s1 << endl;
	// 	if( s1.compare(0,2,"//") == 0 ){
	// 		getline(fin, s1);
	// 		continue;
	// 	}
	// 	if( s1.compare("#define") == 0 ){

	// 	}
	// 	if( s1[0] == '#' || s1[0] == '{' )
	// 		fout << endl;
	// 	fout << s1 << " ";
	// 	if( s1[s1.length()-1 ] == ';' || s1[s1.length()-1 ] == '}')
	// 		fout << endl;
	// }

	s1= "";
	while( !fin.eof() ){
		getline( fin, s2 );
		s1+= s2+"\n";
	}
	// fout << s1;
	n= 0;
	while( n < s1.length() ){
		switch( s1[n] ){
			case '#':
				s2= getOnlyString(s1, n+1);
				n+= s2.length()+2;
				// cout << s1.length() << endl;
				// fout << s1 << endl;
				if( !s1.compare( "include" ) ){
					// cout << s1.substr(n, getInclude(s1, n)) << endl;
					n+= getInclude(s1, n);
					// cout << s2[n] << endl;
				}
				else { // define
					string s3= getOnlyString(s1, n);
					s2= getLine(s1, n);
					mapDefine.insert( MP(s3, Define(s2) ) );
					cout << mapDefine.size() << endl;
					n+= s2.length()+1;
					// n+= s2.length();
					// cout << s2 << endl;
					// string s3;
					// if( s1[n] == '(' )
					// 	s3= getInBracket(s1, n);
					// else
					// 	s3= getString(s1, n);
					// n+= s3.length();
					// s3= s2+s3;
					// string s4= getLine(s1, n+1);

					// cout << s3 << " : " << s4 << endl;
				}
				continue;
			// case ' ':
			// case '\t':
			// case '\n':
			// 	n++;
			// 	continue;
			case '/':
				if( s1[n+1] == '/' )
					n+= getLine(s1, n).length();
				// continue;
			default: ;
		}
		fout << s1[n++];
	}


	return 0;
}
