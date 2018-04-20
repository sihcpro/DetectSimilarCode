# 1 "./Process/27.901.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/27.901.cpp"
# 13 "./Process/27.901.cpp"
int main()
{
 int l, n;
 cin >> l >> n;
 vector<int> a;
 a.resize(n);

 for (int i = 0; i < n; i++)
  cin >> a[i];

 int min_time = -1;
 for (int i = 0; i < n; i++)
  min_time = max(min_time, min(a[i], l - a[i]));
 int max_time = -1;
 for (int i = 0; i < n; i++)
  max_time = max(max_time, max(a[i], l - a[i]));

 cout << min_time << " " << max_time << endl;

 return 0;
}
