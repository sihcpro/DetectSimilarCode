





int(){
std::ios::sync_with_stdio(false);



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
multiset.insert(a[long]);







for(itr=multiset.begin();itr!=multiset.lower_bound(x[long]);++itr)
{
ans+=(*itr-x[long-1]);
}
multiset.erase(multiset.begin(),multiset.lower_bound(x[long]));

ans+=(x[long]-x[long-1])*multiset.size();
cout<<ans<<"";
}


}

