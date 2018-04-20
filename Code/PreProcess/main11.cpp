
#define F(i,n) for(int i=1;i<=n;i++)

#define ull long long int 
ull n;
ull v[1000000];
ull t[1000000];
vector<ull> c(100009,0);
vector<ull> d(100009,0);
int upper_bound1(int start,int last,ull x)
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
    F(i,n) cin>>v[i];
    F(i,n) cin>>t[i], t[i]=t[i]+t[i-1];
    // one extra so when volume is larger than last the upperbound give n+1 value which make to subtract nth value
    t[n+1]=t[n];
    ull x=0;
    for(int i=1;i<=n;i++)
    {
        c[i]++;
        int pos=upper_bound1(i,n+1,v[i]+t[i-1]);
        c[pos]--;
        d[pos]+=v[i]+t[i-1]-t[pos-1];
    }
    x=0;
    F(i,n)
    {
        x+=c[i];
        d[i]+=x*(t[i]-t[i-1]);
    }
    F(i,n)
        cout<<d[i]<<" ";
    cout<<endl;
}
