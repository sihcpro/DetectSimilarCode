# 1 "./Process/main10.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/main10.cpp"
# 32 "./Process/main10.cpp"
void solve() {
 int n;
 cin >> n;
 vector<int> a(n);
 vector<long long> t(n), sum(n);
 for (int i = 0; i < n; i++) {
  cin >> a[i];
 }
 for (int i = 0; i < n; i++) {
  cin >> t[i];
  sum[i] = t[i];
  if (i) {
   sum[i] += sum[i - 1];
  }
 }
 vector<long long> ans(n);
 vector<long long> pr(n + 1);
 for (int i = 0; i < n; i++) {
  int l = i, r = n - 1;
  int cur = -1;
  while (l <= r) {
   int c = (l + r) / 2;
   long long tmp = sum[c];
   if (i) {
    tmp -= sum[i - 1];
   }
   if (tmp <= a[i]) {
    cur = c;
    l = c + 1;
   }
   else {
    r = c - 1;
   }
  }
  if (cur != -1) {
   long long tmp = sum[cur];
   if (i) {
    tmp -= sum[i - 1];
   }
   tmp = a[i] - tmp;
   if (cur != n - 1) {
    ans[cur + 1] += tmp;
   }
   pr[i]++;
   pr[cur + 1]--;
  }
  else {
   ans[i] += a[i];
  }
 }
 for (int i = 1; i < n; i++) {
  pr[i] += pr[i - 1];
 }
 for (int i = 0; i < n; i++) {
  ans[i] += t[i] * pr[i];
 }
 for (int i = 0; i < n; i++) {
  cout << ans[i] << " ";
 }
}

int main() {
 ios_base::sync_with_stdio(false);







 solve();

 return 0;
}
