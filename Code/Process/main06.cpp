


const int N=100100;
#define ll long long 
int i,j,k,n,ch,ff;
ll T;
multiset<ll> S;
int a[N];
void R(int &x) {
	ff=x=0;ch=getchar();
	while (ch<'0' || '9'<ch) { if (ch=='-') ff=1;ch=getchar();}
	while ('0'<=ch && ch<='9') x=x*10+ch-'0',ch=getchar();
	if (ff) x=-x;
}
void W(ll x) {
	if (x<0) x=-x;
	if (x>=10) W(x/10);
	putchar(x%10+'0');
}
int main() {
	R(n);
	for (i=1;i<=n;i++) R(a[i]);
	for (i=1;i<=n;i++) {
		if (a[i]) S.insert(a[i]+T);
		int t;
		ll ans=0;
		R(t);
		while (!S.empty() && *(S.begin())<=T+t) {
			ans+=*(S.begin())-T;
			S.erase(S.begin());
		}
		ans+=(ll) t*S.size();
		W(ans);putchar(' ');
		T+=t;
	}
	puts("");
}
35