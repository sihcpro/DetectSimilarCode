



#define endl                           '\n'
#define mk                             make_pair
#define pb                             push_back
#define REP(i, a, b)                   for (int i = int(a); i < int(b); ++i)
#define rREP(i, a, b)                  for (int i = int(a); i > int(b); --i)
#define ALL(v)				           ((v).begin()), ((v).end())
#define toInt(x)                       (x - '0')
#define UNIQUE(c)                      (c).resize(unique(ALL(c)) - (c).begin())
#define clr(a, b)                      memset((a), (b), sizeof(a))
#define F                              first
#define S                              second
#define popcnt(x)                      __builtin_popcount(x)
#define WHITE 0
#define GRAY  1
#define BLACK 2
//             bit masking
#define isOn(S, j)                     (S & (1 << j))
#define setBit(S, j)                   (S |= (1 << j))
#define clearBit(S, j)                 (S &= ~(1 << j))
#define toggleBit(S, j)                (S ^= (1 << j))
#define lowBit(S)                      (S & (-S))
#define setAll(S, n)                   (S = (1 << n) - 1)

#define modulo(S, N)                   ((S) & (N - 1))   // returns S % N, where N is a power of 2
#define isPowerOfTwo(S)                (!(S & (S - 1)))
#define nearestPowerOfTwo(S)           ((int)pow(2.0, (int)((log((double)S) / log(2.0)) + 0.5)))
#define turnOffLastBit(S)              ((S) & (S - 1))
#define turnOnLastZero(S)              ((S) | (S + 1))
#define turnOffLastConsecutiveBits(S)  ((S) & (S + 1))
#define turnOnLastConsecutiveZeroes(S) ((S) | (S - 1))

#define ll long long              
#define vi vector <int>           
#define ii pair<int, int>         
#define vii vector <ii>            

const int INF = 1e9+9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

template<class T> inline T mod(T a, T b) { return (a%b + b) % b; } //for -ve numbers

int n, ed[N];
ll arr[N], t[N], rm[N], a[N], ans[N];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
#ifndef ONLINE_JUDGE
    //freopen("input.txt", "r", stdin); freopen("output.txt", "w", stdout);
#endif // ONLINE_JUDGE
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> arr[i];
    for(int i = 1; i <= n; ++i) cin >> t[i], a[i] = t[i];
    for(int i = 1; i <= n; ++i) t[i] += t[i-1];
    for(int i = 1; i <= n; ++i){
        int x = lower_bound(t+1, t+n+1, arr[i]+t[i-1])-t;
        ++ed[x];
        rm[x] += (t[x]-t[i-1])-arr[i];
    }
    int cnt = 1;
    for(int i = 1; i <= n; ++cnt, ++i){
        ans[i] += cnt*a[i];
        ans[i] -= rm[i];
        cnt -= ed[i];
//        ans[i] -= ans[i-1];
        cout << ans[i] << ' ';
    }
    return 0;
}
