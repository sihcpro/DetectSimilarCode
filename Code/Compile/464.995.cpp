# 1 "./Process/464.995.cpp"
# 1 "<built-in>"
# 1 "<command-line>"
# 1 "/usr/include/stdc-predef.h" 1 3 4
# 1 "<command-line>" 2
# 1 "./Process/464.995.cpp"


int main(){
 int l, n;
 scanf("%d %d", &l, &n);
 int A[n];
 for(int i=0; i<n; i++){
  scanf("%d", &A[i]);
 }
 int min = A[n/2];
 l-min<min-1 ? min = l-min : min = min-1;
 int max;
 l-A[0]>A[n-1]-1 ? max = l-A[0] : max = A[n-1]-1;
 printf("%d %d", min, max);
 return 0;
}
17
