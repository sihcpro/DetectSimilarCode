BaiCint(){cin>>long>>long;vector.resize(long);for(long<long;long++)cin>>vector[long];for(long<long;long++)long=max(long,min(vector[long],long-vector[long]));for(long<long;long++)long=max(long,max(vector[long],long-vector[long]));cout<<long<<""<<long<<endl;return0;}