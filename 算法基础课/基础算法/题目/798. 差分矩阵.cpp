#include <bits/stdc++.h>

using namespace std;

const int N = 1e3 + 10;
int a[N][N] , b[N][N];
void insert(int x1 , int x2 , int y1 , int y2 , int c) {
	b[x1][y1]     += c;
	b[x1][y2+1]   -= c;
	b[x2+1][y1]   -= c;
	b[x2+1][y2+1] += c;
	return;
}
int main() {
	int n,m,q;
	scanf("%d%d%d",&n,&m,&q);
	
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
			scanf("%d",&a[i][j]);
	
	for (int i = 1 ; i <= n ; i++)
		for(int j = 1 ; j <= m ; j++)
			insert(i,i,j,j,a[i][j]);
	
	while (q--){
		int x1 , x2 , y1 , y2 ,c;
		scanf("%d%d%d%d%d",&x1,&y1,&x2,&y2,&c);
		insert(x1,x2,y1,y2,c);
	}
	for (int i = 1 ; i <= n ; i++)
		for (int j = 1 ; j <= m ; j++)
			a[i][j] = b[i][j] + a[i-1][j] + a[i][j-1] - a[i-1][j-1];
	
	for (int i = 1 ; i <= n ; i++) 
	{
		for (int j = 1 ; j <= m ; j++)
			printf("%d ",a[i][j]);
		puts("");
	}
	return 0;
}
