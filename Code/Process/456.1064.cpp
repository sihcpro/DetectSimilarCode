


int main(){
    int n, k, mid, x, cnt=0;
    cin>>n>>k;
    int a[k], minL=n, maxR=0;
    mid=n/2;
    for(int i=0; i<k; i++){
        scanf("%d", &x);
        if(x!=n and x!=0){
             a[cnt]=x, cnt++;
        }
    }
    sort(a, a+cnt);
    int maxL=a[0], minR=a[cnt-1];
    for(int i=0; i<cnt; ++i){
        
        if(mid>=a[i]) maxL=max(maxL, a[i]);
        else minR=min(minR, a[i]);
    }
    
    cout<<max(maxL, n-minR)<<" "<<max(n-a[0], n-a[cnt-1]);
    return 0;
}
25