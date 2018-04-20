


int()
{
ios_base::sync_with_stdio(0);
cin.tie(NULL);

cin>>long>>long;
for(long<=(long);long++)
cin>>a[long];
sort(a+1,a+long+1);
if(long%2==1)
cout<<min(a[long/2+1]-0,long-a[long/2+1])<<"";
else
cout<<min(a[long/2]-0,long-a[long/2+1])<<"";
cout<<max(a[1]-0,max(long-a[1],max(a[long]-0,long-a[long])));
return0;
}

