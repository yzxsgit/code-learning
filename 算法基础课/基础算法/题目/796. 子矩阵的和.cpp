#include <bits/stdc++.h>

using namespace std;

const int N = 1010;

int a[N][N];
int main() {
	int n , m , q , x1 , x2 , y1 , y2;
	scanf("%d%d%d",&n,&m,&q);
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
			scanf("%d",&a[i][j]);
	
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
			a[i][j] = a[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
	
	while (q--) {
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
		printf("%d\n",a[x2][y2] - a[x1-1][y2] - a[x2][y1-1] + a[x1-1][y1-1]);
	}
	return 0;
}
