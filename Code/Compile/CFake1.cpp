# 1 "./Process/CFake1.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/CFake1.cpp"


long long *____ = new long long[100005];
long long _(long long sidx, long long eidx, long long search_val) {

   if( sidx == eidx )
      return ____[sidx] <= search_val ? sidx : 0;

   long long midx = sidx + (eidx - sidx) / 2;

   if( search_val < ____[midx] )
      return _( sidx, midx, search_val );

   long long ret = _( midx+1, eidx, search_val );
   return ret == 0 ? midx : ret;
}

int main(){
 long long __, ___;
 cin >> __ >> ___;
 long long _____ = 1;
 while(_____ <= __){
  cin >> ____[_____];
  _____++;
 }
 double mx = 0;
 int ________ = 0;
 _____ = 1;
 while(_____ <= __){
  long long ______ = _(_____, __, ____[_____] + ___);
  if(______ - _____ >= 2){
   ________ = 1;
   mx = max(mx, ((double)(____[______] - ____[_____ + 1]) / (double)(____[______] - ____[_____])));

  }
  _____++;
 }
 if(________ == 0) cout << -1;
 else cout << fixed << setprecision(9) << mx;
}
