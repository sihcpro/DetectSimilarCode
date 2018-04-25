#include<bits/stdc++.h>

int main(){
	int l, n;
	scanf("%d %d", &l, &n);
	int *A = (int*)malloc(n*sizeof(int));
	for(int i=0; i<n; i++){
		scanf("%d", &A[i]);
	}
	int min = A[n/2];
	l-min<min-1 ? min = l-min : min = min-1;
	int max;
	l-A[0]>A[n-1] ? max = l-A[0] : max = A[n-1];
	
	printf("%d %d", min, max);
	free(A);
	return 0;
}