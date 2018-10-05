# 1 "./Process/464.1027.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/464.1027.cpp"

int main()
{
 int l, n,tam;
 int *conkien,*dil,max,min=0,max2=0,min2=1000001;
 scanf("%d%d",&l,&n);
 conkien=(int*)malloc(n*sizeof(int));
 dil=(int*)malloc(n*sizeof(int));
 for (int i=0; i<n; i++)
 {
  scanf("%d",&conkien[i]);
  dil[i]=l-conkien[i];
 }
 for (int i=0; i<n-1; i++)
  for (int j=i+1; j<n; j++)
  {
   if (conkien[i]>conkien[j])
   {
    tam=conkien[i];
    conkien[i]=conkien[j];
    conkien[j]=tam;
   }
   if (dil[i]>dil[j])
   {
    tam=dil[i];
    dil[i]=dil[j];
    dil[j]=tam;
   }
  }


 if (n%2!=0) min=conkien[(n/2)];
 else
 {
  if (conkien[(n-1)/2]>l-conkien[((n-1)/2)+1]) min=conkien[(n-1)/2];
  else min=l-conkien[((n-1)/2)+1];
 }
 if (conkien[n-1]>dil[n-1]) max=conkien[n-1];
 else max=dil[n-1];
 if (min>l/2) min=l-min;
 printf("%d %d",min,max);
 return 0;

}
