








int(){
scanf("%d",&long);
for(long<=long;long++)scanf("%lld",&V[long]);
for(long<=long;long++){
scanf("%lld",&long[long]);
sum[long]=sum[long-1]+long[long];
}


for(long<=long;long++){

ans[long]+=long[long-1]+V[long]-long[long-1];
priority_queue.push(long);

while(!priority_queue.empty()){
if(priority_queue.top()<=long)priority_queue.pop();
elsebreak;
}

printf("%lld",long[long]*priority_queue.size()+ans[long]);
}

return0;
}

