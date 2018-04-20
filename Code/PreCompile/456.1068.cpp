# 1 "./PreProcess/456.1068.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./PreProcess/456.1068.cpp"



int main(){
    long int n, k, mid, x, cnt=0;
    cin>>n>>k;
    long int a[k];
    mid=n/2;
    for(int i=0; i<k; i++){
        scanf("%ld", &x);
        if(x!=n and x!=0){
             a[cnt]=x, cnt++;
        }
    }
    sort(a, a+cnt);
    long int maxL=a[0], minR=a[cnt-1];
    for(int i=0; i<cnt; ++i){

        if(mid>=a[i]) maxL=max(maxL, a[i]);
        else{ minR=min(minR, a[i]); break;}
    }

    cout<<max(maxL, n-minR)<<" "<<max(n-a[0], n-a[cnt-1]);
    return 0;
}
