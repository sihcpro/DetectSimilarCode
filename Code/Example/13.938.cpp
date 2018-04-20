#include<bits/stdc++.h>


#define X  first
#define Y  second
typedef long long ll;

#define FOR(i,a,b) for(ll i = a;i<=b;i++)
#define FOD(i,a,b) for(ll i = a;i>=b;i--)
#define pb push_back
#define mp make_pair

using namespace std;

typedef pair<ll,ll>ii;
typedef priority_queue<ll,vector<ll>,greater<ll> > heap_min;
const ll maxN = 1e6+5;
const ll inf = 1e10;
const ll mod = 1e9+7;

ll l,n;
ll a[1000006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>l>>n;
    FOR(i,1,n) cin>>a[i];
    sort(a+1,a+1+n);
    ll resmin=0,resmax=0;
    resmax=max(l-a[1],a[n]);
    FOR(i,1,n)
    {
    	ll tmpmin=min(l-a[i],a[i]);
    	resmin=max(resmin,tmpmin);
	}
	cout<<resmin<<" "<<resmax;
	return 0;
}