# 1 "./Process/434.928.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/434.928.cpp"
# 14 "./Process/434.928.cpp"
priority_queue <long long,vector<int>,greater<int> > heap_min;
set <long long> stang;
set <long long, greater<long long> > sgiam;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    long long l,n,a;
    cin >> l >> n;
    for (int i = (1); i <= (n); i++)
    {
        cin >> a;
        stang.insert(a);
        sgiam.insert(a);
    }
    set <long long>::iterator it1 = stang.lower_bound(l/2);
    set <long long, greater<long long> >::iterator it2 = sgiam.lower_bound(l/2);
    long long minn = max(l - *it1,*it2 - 0);
    it1 = stang.lower_bound(0);
    it2 = sgiam.lower_bound(l);
    cout << minn << " " << max(*it1 - 0, max(l - *it1, max(*it2 - 0, l - *it2)));
    return 0;
}
37
