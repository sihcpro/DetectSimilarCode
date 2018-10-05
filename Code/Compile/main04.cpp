# 1 "./Process/main04.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/main04.cpp"
# 41 "./Process/main04.cpp"
const int INF = 1e9+9;
const double PI = 2 * acos(0.0);
const double eps = 1e-9;
const int NPOS = -1;
const int N = 1e5 + 5;
const int MOD = 1e9 + 7;

template<class T> inline T mod(T a, T b) { return (a%b + b) % b; }

int n, ed[N];
long long arr[N], t[N], rm[N], a[N], ans[N];
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);



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

        cout << ans[i] << ' ';
    }
    return 0;
}
