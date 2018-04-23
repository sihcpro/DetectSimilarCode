#include <bits\stdc++.h>
long long *a = new long long[100005];
long long search(long long start_idx, long long end_idx, long long search_val) {

   if( start_idx == end_idx )
      return a[start_idx] <= search_val ? start_idx : 0;

   long long mid_idx = start_idx + (end_idx - start_idx) / 2;

   if( search_val < a[mid_idx] )
      return search( start_idx, mid_idx, search_val );

   long long ret = search( mid_idx+1, end_idx, search_val );
   return ret == 0 ? mid_idx : ret;
}
using namespace std;
int main(){
	long long n, U;
	cin >> n >> U;
	for(long long i = 1; i <= n; i++) cin >> a[i];
	double mx = 0;
	int flag = 0;
	for(long long i = 1; i <= n; i++){
		long long j = search(i, n, a[i] + U);
		if(j - i >= 2){
			flag = 1;
			mx = max(mx, ((double)(a[j] - a[i + 1]) / (double)(a[j] - a[i])));
//			cout << (a[j] - a[i + 1]) << " " << (a[j] - a[i]) << "|" << ((double)(a[j] - a[i + 1]) / (double)(a[j] - a[i])) << endl;
		}
	}
	if(flag == 0) cout << -1;
	else cout << fixed << setprecision(9) << mx;
}
