# 1 "./Process/13.938.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/13.938.cpp"
# 17 "./Process/13.938.cpp"
const long long maxN = 1e6+5;
const long long inf = 1e10;
const long long mod = 1e9+7;

long long l,n;
long long a[1000006];

int main()
{
    ios_base::sync_with_stdio(0);
    cin>>l>>n;
    for(long long i = 1;i<=n;i++) cin>>a[i];
    sort(a+1,a+1+n);
    long long resmin=0,resmax=0;
    resmax=max(l-a[1],a[n]);
    for(long long i = 1;i<=n;i++)
    {
     long long tmpmin=min(l-a[i],a[i]);
     resmin=max(resmin,tmpmin);
 }
 cout<<resmin<<" "<<resmax;
 return 0;
}
