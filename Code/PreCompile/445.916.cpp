# 1 "./PreProcess/445.916.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./PreProcess/445.916.cpp"


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
