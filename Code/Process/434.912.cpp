


#define mod 1e9+7
#define X first
#define Y second
#define pb push_back
#define mp make_pair
#define FOR(i,a,b) for (int i = (a); i <= (b); i++)
#define FORE(i,a,b) for (int i = (a); i >= (b); i--)

#define ll long long 
#define ii pair<ll,ll> 
priority_queue <ll,vector<int>,greater<int> > heap_min;
ll a[1000005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int l,n;
    cin >> l >> n;
    FOR(i,1,n)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    if (n%2 == 1)
        cout << min(a[n/2+1] - 0, l - a[n/2+1]) << " ";
    else
        cout << max(a[n/2] - 0, l - a[n/2+1]) << " ";
    cout << max(a[1] - 0, max(l - a[1], max(a[n] - 0, l - a[n])));
    return 0;
}
