# 1 "./PreProcess/441.902.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./PreProcess/441.902.cpp"




int main(){
 int n,l;cin>>l>>n;
 int a[n+1],min=0,max=0;
 for(int i=1;i<=n;i++){
  cin>>a[i];
  if(a[i]>l/2){
   if(l-a[i]>min) min=l-a[i];
   if(a[i]>max)max=a[i];
  }else{
   if(a[i]>min)min=a[i];
   if(l-a[i]>max) max=l-a[i];
  }
 }
 cout<<min<<" "<<max;
}
