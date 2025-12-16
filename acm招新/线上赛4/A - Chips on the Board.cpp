#include <bits/stdc++.h>

using namespace std;
const int N = 300000 + 10 ;
int t,n;
long long a[N],b[N];

int main() {
	scanf("%d",&t);
	while (t--) {
		scanf("%d",&n);
		long long tmpr = 0 , tmpl = 0 , minl = LONG_MAX , minr = LONG_MAX;
		for (int i = 1 ; i <= n ; i++) {
			scanf("%lld",&a[i]);
			tmpl += a[i];
			minl = min(minl,a[i]);
		}
		for (int i = 1 ; i <= n ; i++) {
			scanf("%lld",&b[i]);
			tmpr += b[i];
			minr = min(minr,b[i]);
		}
		long long ans = min(tmpr + n * minl , tmpl + n * minr);
		printf("%lld\n",ans);
	}
	return 0;
} 
