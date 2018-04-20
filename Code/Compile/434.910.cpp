# 1 "./Process/434.910.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/434.910.cpp"
# 14 "./Process/434.910.cpp"
priority_queue <long long,vector<int>,greater<int> > heap_min;
long long a[1000005];

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    int l,n;
    cin >> l >> n;
    for (int i = (1); i <= (n); i++)
        cin >> a[i];
    sort(a + 1, a + n + 1);
    if (n%2 == 1)
        cout << min(a[n/2+1] - 0, l - a[n/2+1]) << " ";
    else
        cout << min(a[n/2] - 0, l - a[n/2+1]) << " ";
    cout << max(a[1] - 0, max(l - a[1], max(a[n] - 0, l - a[n])));
    return 0;
}
