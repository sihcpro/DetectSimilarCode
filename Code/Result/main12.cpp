






vector()cin>>v[i];
for(long<=n;long++)cin>>t[long],t[long]=t[long]+t[long-1];

t[n+1]=t[n];

for(long<=n;long++)
{
vector[long]++;


vector[long]--;
vector[long]+=long[long]+long[long-1]-long[long-1];
}
x=0;
for(long<=n;long++)
{
x+=vector[long];
vector[long]+=x*(t[long]-t[long-1]);
}
for(long<=n;long++)
cout<<vector[long]<<"";
cout<<endl;
}