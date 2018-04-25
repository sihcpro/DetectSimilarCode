# 1 "./Process/11.931.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/11.931.cpp"



int main ()
{
    long long l,n,x;
    long long resmax=0, resmin=0, ansmax, ansmin;
    cin >> l >> n;
    for (int i=0; i<n; i++)
    {
        scanf ("%lld",&x);
        if (x>l-x)
        {
            ansmax=x;
            ansmin=l-x;
        }
        else
        {
            ansmax=l-x;
            ansmin=x;
        }
        resmax=max(resmax,ansmax);
        resmin=max(resmin,ansmin);
    }
    cout << resmin << " " << resmax;
}
