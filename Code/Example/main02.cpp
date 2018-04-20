#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

const int maxn = 100005;


int n;
ll V[maxn], T[maxn], S[maxn], b[maxn];
vector<ll> ans, bal;

int lday(int a){
    int l = a-1, r = n+1;
    while(r-l > 1){
        int m = (l+r)>>1;

        ll sumt = S[m] - S[a-1];
        if(V[a] - sumt > 0) l = m; else r = m;
    }
  return l;
}

int main(){
    //ifstream cin("input.txt");

     cin>>n;
     ans.resize(n+2, 0);
     bal.resize(n+2, 0);
     for(int i = 1; i <= n; i++) cin>>V[i];
     for(int i = 1; i <= n; i++) cin>>T[i];

     T[0] = 0;
     T[n+1] = 1e9;
     S[0] = 0;
     for(int i = 1; i <= n+1; i++) S[i] = S[i-1]+T[i];


    for(int i = 1; i <= n; i++){
        int d = lday(i);
        ll sumt = S[d] - S[i-1];
        ans[d+1] += (V[i] - sumt);
    }

    for(int i = 1; i <= n; i++){
        int d = lday(i);
        bal[i]++;
        bal[d+1]--;
    }

    ll tq = 0;
    for(int i = 1; i <= n; i++){
      tq += bal[i];
      b[i] = tq;
    }

    for(int i = 1; i <= n; i++) ans[i] += b[i]*T[i];

    for(int i = 1; i <= n; i++) cout<<ans[i]<<' ';

}