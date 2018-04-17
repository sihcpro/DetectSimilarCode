#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

typedef long long ll;

int main() {
    int n;
    cin >> n;
    vector<ll> v(n + 1), t(n + 1), rest(n + 1);
    vector<ll> sum(n + 1);
    vector<vector<int>> u(n + 2);
    for (int i = 1; i <= n; i++) {
        cin >> v[i];
    }
    for (int i = 1; i <= n; i++) {
        cin >> t[i];
        sum[i] = t[i] + sum[i - 1];
    }
    for (int i = 1; i <= n; i++) {
        int l = i - 1, r = n + 1;
        while (l < r) {
            int m = (l + r) / 2;
            if (sum[m] - sum[i - 1] < v[i]) {
                l = m + 1;
            } else {
                r = m;
            }
        }
        rest[i] = v[i] - sum[l - 1] + sum[i - 1];
        u[l].push_back(i);
    }
    ll cnt = u[0].size();
    for (int i = 1; i <= n; i++) {
        ll ans = 0;
        cnt += u[i].size();
        ans += t[i] * (i - cnt);
        for (int j = 0; j < u[i].size(); j++) {
            ans += rest[u[i][j]];
        }
        cout << ans << ' ';
    }
    cout << endl;
}