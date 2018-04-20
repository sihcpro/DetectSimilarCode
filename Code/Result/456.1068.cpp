


int(){

cin>>n>>long;

long=n/2;
for(long<long;long++){
scanf("%ld",&long);
if(long!=nandlong!=0){
a[long]=long,long++;
}
}
sort(a,a+long);

for(long<long;++long){

if(long>=a[long])maxL=max(maxL,a[long]);
else{long=min(long,a[long]);break;}
}

cout<<max(maxL,n-long)<<""<<max(n-a[0],n-a[long-1]);
return0;
}

