# 1 "./PreProcess/62.935.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./PreProcess/62.935.cpp"



int main()
{
 long l,i,n=100;
 scanf("%ld%ld",&l,&n);
 long A[n];
 int max,min=0;
 for(i=0;i<n;i++)
 {
  scanf("%ld",&A[i]);
 }
 int m=0,temp,t=0;
 while(m=0)
 {
  for(i=0;i<n;i++)
  if(A[i+1]<A[i]) {
   temp=A[i+1];
   A[i+1]=A[i];
   A[i]=temp;
   t=1;
  }
  if(t==1) break;
 }


 if(A[n-1]>(l-A[0])) max=A[n-1];
 else max=l-A[0];

 int k=l/2;
 for(i=0;i<n;i++)
 {
  if((A[i]<=k)&&(A[i]>min)) min=A[i];
  if((A[i]>=k)&&((l-A[i])>min)) min=l-A[i];
 }
 printf("%d %d",min,max);
 return 1;

}