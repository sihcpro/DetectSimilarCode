



long long int a[100010];
long long int x[100010];
int main(){
	std::ios::sync_with_stdio(false);
	multiset <long long int> s;  
	multiset <long long int> :: iterator itr;
	long long int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a[i];
	}
	for(int i=0;i<t;i++){
		cin>>x[i];
	}
	long long int p=x[0];
	for(int i=1;i<t;i++){
		a[i]+=p;
		p+=x[i];
		x[i]=p;
	}
	// for(int i=0;i<t;i++){
	// 	cout<<a[i]<<" ";
	// }
	// cout<<endl;
	for(int i=0;i<t;i++){
		s.insert(a[i]);
		long long int ans =0;
		// for (itr = s.begin(); itr != s.end(); ++itr)
		//     {
		//         cout<<*itr<<" ";
		//     }
		//     cout<<endl;
		// cout<<*s.lower_bound(x[i])<<"==";
		for (itr = s.begin(); itr != s.lower_bound(x[i]); ++itr)
	    {
	        ans+=(*itr - x[i-1]);
	    }
	    s.erase(s.begin(), s.lower_bound(x[i]));
		//cout<<ans<<" "<<s.size()<<" ";
		ans+=(x[i]-x[i-1])*s.size();
		cout<<ans<<" ";
	}
	

}
