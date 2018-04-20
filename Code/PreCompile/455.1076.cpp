# 1 "./PreProcess/455.1076.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./PreProcess/455.1076.cpp"


long long a[1000001] ;
int main()
{

    long long l , n ; cin >> l >> n ;
    for(long long i = 0 ; i < n; i++ ) {
        cin >> a[i] ;
    }
    long long k = l/2;
    sort(a,a+n) ;
    long long min1 = 0 ;
    long long min2 = 0 ;
    for(long long i = 0 ; i < n ; i++ ) {
        if(a[i] <= k ){
            min1 = max(min1,a[i]) ;
        }
        else {
            min1 = max(min1 , l - a[i]) ;
        }
    }
    cout << min1 << " " ;
    for(long long i = 0 ; i < n ; i++ ) {
        min2 = max(min2,a[i]) ;
        min2 = max(l-a[i],min2) ;
    }
    cout << min2 << endl;
}
