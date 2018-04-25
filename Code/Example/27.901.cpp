#include <iostream>
#include <map>
#include <queue>
#include <algorithm>
#include <set>
#include <cmath>
#include <string>
#include <stack>
#include <functional>

using namespace std;

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