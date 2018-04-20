








void(){
long=x=0;long=getchar();
while(long<'0'||'9'<long){if(long=='-')long=1;long=getchar();}
while('0'<=long&&long<='9')x=x*10+long-'0',long=getchar();
if(long)x=-x;
}
void(){
if(x<0)x=-x;
if(x>=10)void(x/10);
putchar(x%10+'0');
}
int(){
void(long);
for(long=1;long<=long;long++)void(long[long]);
for(long=1;long<=long;long++){
if(long[long])multiset.insert(long[long]+T);


void(long);
while(!multiset.empty()&&*(multiset.begin())<=T+long){
ans+=*(multiset.begin())-T;
multiset.erase(multiset.begin());
}
ans+=(long)long*multiset.size();
void(ans);putchar('');
T+=long;
}
puts("");
}

