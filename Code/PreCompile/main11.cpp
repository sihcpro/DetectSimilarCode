# 1 "./PreProcess/main11.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./PreProcess/main11.cpp"




long long int n;
long long int v[1000000];
long long int t[1000000];
vector<long long int> c(100009,0);
vector<long long int> d(100009,0);
int upper_bound1(int start,int last,long long int x)
{
    int l=start;
    int h=last;
    int mid;
    while(l<h)
    {
        mid=(l+h)/2;
        if(t[mid]==x)
            return mid;
        else if(t[mid]<x)
            l=mid+1;
        else
            h=mid-1;
    }
    if(x<t[h])
        return h;
    else
        return h+1;
}
int main()
{
    cin>>n;
    v[0]=t[0]=0;
    for(int i=1;i<=n;i++) cin>>v[i];
    for(int i=1;i<=n;i++) cin>>t[i], t[i]=t[i]+t[i-1];

    t[n+1]=t[n];
    long long int x=0;
    for(int i=1;i<=n;i++)
    {
        c[i]++;
        int pos=upper_bound1(i,n+1,v[i]+t[i-1]);
        c[pos]--;
        d[pos]+=v[i]+t[i-1]-t[pos-1];
    }
    x=0;
    for(int i=1;i<=n;i++)
    {
        x+=c[i];
        d[i]+=x*(t[i]-t[i-1]);
    }
    for(int i=1;i<=n;i++)
        cout<<d[i]<<" ";
    cout<<endl;
}
