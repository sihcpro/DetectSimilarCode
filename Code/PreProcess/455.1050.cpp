

int main()
{
    int a[10001] ;
    int l , n ; cin >> l >> n ;
    for(int i = 0 ; i < n; i++ ) {
        cin >> a[i] ;
    }
    int k = l/2;
    //sort(a,a+n) ;
    int min1 = 0 ;
    int min2 = 0 ;
    for(int i = 0 ; i < n ; i++ ) {
        if(a[i] < k ){
            min1 = max(min1,a[i]) ;
        }
        else {
            min1 = max(min1 , l - a[i]) ;
        }
    }
    cout << min1 << " " ;
    for(int i = 0 ; i < n ; i++ ) {
        min2 = max(l-a[i],min2) ;
    }
    cout << min2 << endl;
}
