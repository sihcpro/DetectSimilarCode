


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
set <ll> stang;
set <ll, greater<ll> > sgiam;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    ll l,n,a;
    cin >> l >> n;
    FOR(i,1,n)
    {
        cin >> a;
        stang.insert(a);
        sgiam.insert(a);
    }
    set <ll>::iterator it1 = stang.lower_bound(l/2);
    set <ll, greater<ll> >::iterator it2 = sgiam.lower_bound(l/2);
    ll minn =  max(l - *it1,*it2 - 0);
    it1 = stang.lower_bound(0);
    it2 = sgiam.lower_bound(l);
    cout << minn << " " << max(*it1 - 0, max(l - *it1, max(*it2 - 0, l - *it2)));
    return 0;
}
