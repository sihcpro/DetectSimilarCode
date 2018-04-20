





int(){
std::ios::sync_with_stdio(false);
multiset<
multiset<

cin>>t;
for(long<t;long++){
cin>>a[long];
}
for(long<t;long++){
cin>>x[long];
}

for(long<t;long++){
a[long]+=p;
p+=x[long];
x[long]=p;
}




for(long<t;long++){
s.insert(a[long]);







for(itr=s.begin();itr!=s.lower_bound(x[long]);++itr)
{
ans+=(*itr-x[long-1]);
}
s.erase(s.begin(),s.lower_bound(x[long]));

ans+=(x[long]-x[long-1])*s.size();
cout<<ans<<"";
}


}

