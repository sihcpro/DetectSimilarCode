


int main(){
    int n, k, mid, maxL=0;
    cin>>n>>k;
    int a[k+1], minL=n, maxR=1, minR=n;
    mid=k%2==0?k/2:k/2+1;
    for(int i=0; i<k; i++){
        scanf("%d", &a[i]);
        if(mid>=a[i]) maxL=max(maxL, a[i]);
        else minR=min(minR, a[i]);
        minL=min(a[i], minL);
        maxR=max(a[i], maxR);
    }
    cout<<min(n-maxL, n-minR)<<" "<<max(n-minL, n-maxR)<<endl;
    return 0;
}
18