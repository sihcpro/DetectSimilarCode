void(){

cin>>long;
vector();
vector(),sum();
for(long=0;long<;long++){
cin>>vector[long];
}
for(long=0;long<;long++){
cin>>vector[long];
sum[long]=vector[long];
if(long){
sum[long]+=sum[long-1];
}
}
vector();
vector();
for(long=0;long<;long++){
long=long;long=n-1;
long=-1;
while(long<=long){
long=(long+long)/2;
long=sum[long];
if(long){
long-=sum[long-1];
}
if(long<=vector[long]){
long=long;
long=long+1;
}
else{
long=long-1;
}
}
if(long!=-1){
long=sum[long];
if(long){
long-=sum[long-1];
}
long=vector[long]-long;
if(long!=-1){
vector[long+1]+=long;
}
vector[long]++;
vector[long+1]--;
}
else{
vector[long]+=vector[long];
}
}
for(long=1;long<;long++){
vector[long]+=vector[long-1];
}
for(long=0;long<;long++){
vector[long]+=vector[long]*vector[long];
}
for(long=0;long<;long++){
cout<<vector[long]<<" ";
}
}

int(){
ios_base::sync_with_stdio(false);







void();

return0;
}
84

