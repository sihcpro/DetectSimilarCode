# 1 "./PreProcess/main02.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./PreProcess/main02.cpp"





const int maxn = 100005;


int n;
long long V[maxn], T[maxn], S[maxn], b[maxn];
vector<long long> ans, bal;

int lday(int a){
    int l = a-1, r = n+1;
    while(r-l > 1){
        int m = (l+r)>>1;

        long long sumt = S[m] - S[a-1];
        if(V[a] - sumt > 0) l = m; else r = m;
    }
  return l;
}

int main(){


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
        long long sumt = S[d] - S[i-1];
        ans[d+1] += (V[i] - sumt);
    }

    for(int i = 1; i <= n; i++){
        int d = lday(i);
        bal[i]++;
        bal[d+1]--;
    }

    long long tq = 0;
    for(int i = 1; i <= n; i++){
      tq += bal[i];
      b[i] = tq;
    }

    for(int i = 1; i <= n; i++) ans[i] += b[i]*T[i];

    for(int i = 1; i <= n; i++) cout<<ans[i]<<' ';

}
