#include <bits/stdc++.h>

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

string getString(string &str, int start_pos){
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

	s2= "";
	while( !fin.eof() ){
		getline( fin, s1 );
		s2+= s1+"\n";
	}
	// fout << s2;
	n= 0;
	while( n < s2.length() ){
		switch( s2[n] ){
			case '#':
				s1= getString(s2, n+1);
				n+= s1.length()+2;
				// cout << s1.length() << endl;
				// fout << s1 << endl;
				if( !s1.compare( "include" ) ){
					// cout << s2.substr(n, getInclude(s2, n)) << endl;
					n+= getInclude(s2, n);
					// cout << s2[n] << endl;
				}
				else { // define

				}
				continue;
			case ' ':
			case '\t':
			case '\n':
				n++;
				continue;
			case '\\':
				if( s2[n+1] == '\\' )
			default: ;
		}
		fout << s2[n++];
	}


	return 0;
}
