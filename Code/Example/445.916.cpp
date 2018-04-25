#include <bits/stdc++.h>
using namespace std;
int main()
{
    long long l,n, maxa=0, mina = 0,u,v;
    cin >> l >> n;
    while (n--)
    {
        long long a;
        cin >> a;
        u = min(a,l-a);
        v = max(a,l-a);
        if (mina < u) mina = u;
        if (maxa < v) maxa = v;
    }
    cout << mina << " " << maxa;
    return 0;
}