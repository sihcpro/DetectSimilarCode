#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#define push_back pb
#define make_pair mp
#define first ff
#define second ss


















#define ll long long 
#define vi vector<int> 
#define ld long double 
#define vll vector<ll> 
#define pll pair<ll, ll> 
#define pii pair<int, int> 

void solve() {
	int n;
	cin >> n;
	vi a(n);
	vll t(n), sum(n);
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
	vll ans(n);
	vll pr(n + 1);
	for (int i = 0; i < n; i++) {
		int l = i, r = n - 1;
		int cur = -1;
		while (l <= r) {
			int c = (l + r) / 2;
			ll tmp = sum[c];
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
			ll tmp = sum[cur];
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
#ifdef _DEBUG
	freopen("in.txt", "r", stdin);
	freopen("out.txt", "w", stdout);
#elif ONLINE_JUDGE
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
#endif
	solve();

	return 0;
}
