#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main(){
	int l, n;
	int temp;
	cin>>l>>n;
	int maxk = 0;
	int mink = 0;
	for(int i=0; i<n ;i++){
		cin>>temp;
		if((l-temp)>temp){
			maxk = max(maxk,l-temp);
			mink = max(mink, temp);	
		}
		else{
			maxk = max(maxk,temp);
			mink = max(mink, l-temp);	
		}
	}
	cout<<mink<<" "<<maxk;
}