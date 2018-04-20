


int()
{

cin>>l>>long;
for(i<long;i++){
cin>>a[i];
}

sort(a,a+long);


for(i<long;i++){
if(a[i]<=k){
min1=max(min1,a[i]);
}
else{
min1=max(min1,l-a[i]);
}
}
cout<<min1<<"";
for(i<long;i++){
min2=max(l-a[i],min2);
}
cout<<min2<<endl;
}

