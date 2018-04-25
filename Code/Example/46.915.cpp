#include<bits/stdc++.h>
using namespace std;
main()
{
	int l,n;
	
	cin>>l;
	cin>>n;
	int a[n];
	int min=l/2;
	for(int i=0;i<n;i++)
	{	cin>>a[i];
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
}