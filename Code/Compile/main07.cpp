# 1 "./Process/main07.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/main07.cpp"




int n;
long long V[100005],T[100005];
long long sum[100005];
long long ans[100005];

int main(){
 scanf("%d",&n);
 for(int i=1;i<=n;i++) scanf("%lld",&V[i]);
 for(int i=1;i<=n;i++) {
  scanf("%lld",&T[i]);
  sum[i]=sum[i-1]+T[i];
 }

 priority_queue<int,vector<int>,greater<int> > pq;
 for(int i=1;i<=n;i++){
  int k=upper_bound(sum,sum+n+1,sum[i-1]+V[i])-sum;
  ans[k]+=sum[i-1]+V[i]-sum[k-1];
  pq.push(k);

  while(!pq.empty()){
   if(pq.top()<=i) pq.pop();
   else break;
  }

  printf("%lld ",T[i]*pq.size()+ans[i]);
 }

 return 0;
}
