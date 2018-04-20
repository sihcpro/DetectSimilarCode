#include <bits/stdc++.h>
#define ll long long
using namespace std;
int main ()
{
    ll l,n,x;
    ll resmax=0, resmin=0, ansmax, ansmin;
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