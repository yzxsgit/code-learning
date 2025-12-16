#include <bits/stdc++.h>

using namespace std;

const int N = 300000+10;
int L[N] , s[N] , R[N] , b[N];
struct dic{
	int key,val;
}a[N];

vector<int> alls;

int find(int x) {
	int l = 0 , r = alls.size() - 1;
	while (l < r) {
		int mid = l + r >> 1;
		if(alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;
}
int main() {
	int n , m , res , l , r;
	scanf("%d%d",&n,&m);
	for (int i = 0 ; i < n ; i++) {
		scanf("%d%d",&a[i].key,&a[i].val);
		alls.push_back(a[i].key);
	}
	for (int i = 0 ; i < m ; i++) {
		scanf("%d%d",&L[i],&R[i]);
		alls.push_back(L[i]);
		alls.push_back(R[i]);
	}
	sort(alls.begin(),alls.end());
	alls.erase(unique(alls.begin(),alls.end()),alls.end());
	
	for (int i = 0 ; i < n ; i++) {
		res = find(a[i].key);
		b[res] += a[i].val;
	}
	for (int i = 1 ; i <= alls.size() ; i++)
		s[i] = b[i] + s[i-1];
	for (int i = 0 ; i < m ; i++) {
		int l = find(L[i]) , r = find(R[i]);
		printf("%d\n",s[r] - s[l-1]);
	}
	return 0;
}
