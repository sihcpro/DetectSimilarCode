#include<bits/stdc++.h>

int main(){
	int l, n;
	scanf("%d %d", &l, &n);
	int *A = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++){
		scanf("%d", &A[i]);
	}
	int min;
	if(n%2 == 0){
		int min1 = A[(n/2)-1], min2 = A[n/2];
		l-min2>min1 ? min = l-min2 : min = min1;
	}
	else if(n%2 == 1){
		min = A[n/2];
		l-min>min ? min = l-min : min = min;
	}
	int max;
	l-A[0]>A[n-1] ? max = l-A[0] : max = A[n-1];
	
	printf("%d %d", min, max);
	free(A);
	return 0;
}