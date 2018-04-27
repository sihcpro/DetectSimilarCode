# 1 "./Process/11.958.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/11.958.cpp"





int main(){
 int l, n;
 int temp;
 cin>>l>>n;
 int maxk = 0;
 int mink = 0;
 for(int i=0; i<n ;i++){
  cin>>temp;
  if((l-temp)>temp){
   maxk = max(maxk,l-temp);
   mink = max(mink, temp);
  }
  else{
   maxk = max(maxk,temp);
   mink = max(mink, l-temp);
  }
 }
 cout<<mink<<" "<<maxk;
}
24
