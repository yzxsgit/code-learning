#include<iostream>
using namespace std;
const int N = 100000;
int q[N],n,m;
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 0 ; i < n ; i++)
		scanf("%d",&q[i]);
	while (m--)	{
		int l = 0 , r = n-1 , ansl , ansr , x , mid;
		scanf("%d",&x);
		while (l < r) {
			mid = l + r  >> 1;
			if (q[mid] >= x) r = mid;
			else l = mid + 1;
		}
		ansl = r;
		l = 0,r = n - 1;
		while(l < r) {
			mid = l + r + 1 >> 1;
			if (q[mid] <= x) l = mid;
			else r = mid - 1;
		}
		ansr = l;
		if (q[l] != x)
			printf("-1 -1\n");
		else
			printf("%d %d\n",ansl,ansr);
	}
	return 0;
}
