# 1 "./Process/46.894.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/46.894.cpp"


int main()
{
 int l,n;
 int a[1000];
 cin>>l;
 cin>>n;
 int min=l/2;
 for(int i=0;i<n;i++)
 { cin>>a[i];
  if(abs(l/2-a[i])<min)
   min=abs(l/2-a[i]);

 }

 min=l/2-min;
 sort(a,a+n);
 cout<<min<<" ";
 int max=a[0];

 if(a[0]<l-a[n-1])
 {
  max= l-a[0];
 }
 else max=a[n-1];


 cout<<max;
 return 1;
}
