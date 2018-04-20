int(){

cin>>long;
vector(),t(long+1),rest(long+1);
vector();
vector();
for(long<=long;long++){
cin>>vector[long];
}
for(long<=long;long++){
cin>>t[long];
vector[long]=t[long]+vector[long-1];
}
for(long<=long;long++){

while(long<long){

if(vector[long]-vector[long-1]<vector[long]){
long=long+1;
}else{
long=long;
}
}
rest[long]=vector[long]-vector[long-1]+vector[long-1];
vector[long].push_back(long);
}

for(long<=long;long++){

cnt+=vector[long].size();
ans+=t[long]*(long-cnt);
for(long<vector[long].size();long++){
ans+=rest[vector[long][long]];
}
cout<<ans<<'';
}
cout<<endl;
}

