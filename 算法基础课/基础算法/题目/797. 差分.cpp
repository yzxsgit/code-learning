#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int a[N],b[N];
void insert(int l , int r , int c) {
	b[l] += c;
	b[r+1] -= c;
	return;
}
int main() {
	int n,m;
	scanf("%d%d",&n,&m);
	for (int i = 1 ; i <= n ; i++)
		scanf("%d",&a[i]);
	
	for (int i = 1 ; i <= n ; i++)
		insert(i,i,a[i]);
	
	while(m--) {
		int l , r , c;
		scanf("%d%d%d",&l,&r,&c);
		insert(l,r,c);
	}
	for (int i = 1 ; i <= n ; i++)
		a[i] = a[i-1] + b[i];
	
	for (int i = 1 ; i <= n ; i++)
		printf("%d ",a[i]);
	
	return 0;
} 
