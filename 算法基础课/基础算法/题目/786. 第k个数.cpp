#include <bits/stdc++.h>
using namespace std;

void quick_sort(int *q,int l ,int r) {
	if(l >= r) return;
	
	int x = q[l + r >> 1] , i = l - 1  , j = r + 1;
	
	while (i < j) {
		while (q[++i] < x);
		while (q[--j] > x);
		if(i < j) swap(q[i],q[j]);
	}
	
	quick_sort(q , l , j);
	quick_sort(q , j+1 , r);
}
const int N = 1000000;
int q[N],n,k;

int main() {
	scanf("%d%d",&n,&k);
	for (int i = 0 ; i < n ; i++)
		scanf("%d",&q[i]);
	
	quick_sort(q,0,n-1);
	
	printf("%d",q[k-1]);
	
	return 0;
}
