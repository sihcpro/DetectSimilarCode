# 1 "./Process/main08.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/main08.cpp"




long long int a[100010];
long long int x[100010];
int main(){
 std::ios::sync_with_stdio(false);
 multiset <long long int> s;
 multiset <long long int> :: iterator itr;
 long long int t;
 cin>>t;
 for(int i=0;i<t;i++){
  cin>>a[i];
 }
 for(int i=0;i<t;i++){
  cin>>x[i];
 }
 long long int p=x[0];
 for(int i=1;i<t;i++){
  a[i]+=p;
  p+=x[i];
  x[i]=p;
 }




 for(int i=0;i<t;i++){
  s.insert(a[i]);
  long long int ans =0;






  for (itr = s.begin(); itr != s.lower_bound(x[i]); ++itr)
     {
         ans+=(*itr - x[i-1]);
     }
     s.erase(s.begin(), s.lower_bound(x[i]));

  ans+=(x[i]-x[i-1])*s.size();
  cout<<ans<<" ";
 }


}
