int(){

cin>>long;
vector(),t(+1),rest(+1);
vector();
vector();
for(long<=;long++){
cin>>vector[long];
}
for(long<=;long++){
cin>>t[long];
vector[long]=t[long]+vector[long-1];
}
for(long<=;long++){

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

for(long<=;long++){

long+=vector[long].size();
long+=t[long]*(long-long);
for(long<vector[long].size();long++){
long+=rest[vector[long][long]];
}
cout<<long<<' ';
}
cout<<endl;
}

