int()
{

cin>>long>>long;

vector.resize(long);

for(long=0;long<long;long++)
cin>>vector[long];

long=-1;
for(long=0;long<long;long++)
long=max(long,min(vector[long],long-vector[long]));
long=-1;
for(long=0;long<long;long++)
long=max(long,max(vector[long],long-vector[long]));

cout<<long<<" "<<long<<endl;

return0;
}
33

