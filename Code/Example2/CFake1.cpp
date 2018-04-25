#include <bits\stdc++.h>
typedef long long llong;
llong *____ = new llong[100005];
llong _(llong sidx, llong eidx, llong search_val) {

   if( sidx == eidx )
      return ____[sidx] <= search_val ? sidx : 0;

   llong midx = sidx + (eidx - sidx) / 2;

   if( search_val < ____[midx] )
      return _( sidx, midx, search_val );

   llong ret = _( midx+1, eidx, search_val );
   return ret == 0 ? midx : ret;
}
using namespace std;
int main(){
	llong __, ___;
	cin >> __ >> ___;
	llong _____ = 1;
	while(_____ <= __){
		cin >> ____[_____];
		_____++;
	}
	double mx = 0;
	int ________ = 0;
	_____ = 1;
	while(_____ <= __){
		llong ______ = _(_____, __, ____[_____] + ___);
		if(______ - _____ >= 2){
			________ = 1;
			mx = max(mx, ((double)(____[______] - ____[_____ + 1]) / (double)(____[______] - ____[_____])));
//			cout << (____[______] - ____[_____ + 1]) << " " << (____[______] - ____[_____]) << "|" << ((double)(____[______] - ____[_____ + 1]) / (double)(____[______] - ____[_____])) << endl;
		}
		_____++;
	}
	if(________ == 0) cout << -1;
	else cout << fixed << setprecision(9) << mx;
}

