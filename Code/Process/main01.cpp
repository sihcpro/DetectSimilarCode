
// 



#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define ldb ldouble
#define PI 3.14159265

//#define t3 tuple<int, int, int> 
// #define ll lll lll
// #define lll long long 
#define ll long long 
#define ull unsigned long long 
#define db double 
#define ld long double 
#define pii pair <int, int> 
#define pll pair <ll, ll> 
#define pli pair <ll, int> 
#define pdd pair <db, db> 

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

#define cap ll 
#define pqmax priority_queue<cap> 
#define pqmin priority_queue<cap, vector<cap>, greater<cap> > 

ll junger= 0, mid= 0, top= 0, bot= 0, result= 0, sum= 0, s= 0, t= 0, d= 0, l= 0, sp= 0, k= 0, x, y, n, m, test, r;
bool kt= false, t1= false, t2= false;
string s1, s2;

int tl[55], nh[55];
string st[55];

int a[100];
/* I want to right something down :D
And you have to delete it! :v
*/
#define ll long long
#define ll long

int main()
{
	// freopen("test.txt", "r", stdin);
	
	cin >> test;

	while( test-- ){
		cin >> n;

		int sp;
		pqmin h;
		rep(0,i,n){cin >> sp;
			h.push(sp);
		}

		s= 0;
		while( h.size() > (long)1 ){
			x= h.top(); h.pop();
			y= h.top(); h.pop();
			s+= x+y;
			h.push(x+y);
		}

		cout << s << endl;
	}

	

	return 0;
}

/**/
80