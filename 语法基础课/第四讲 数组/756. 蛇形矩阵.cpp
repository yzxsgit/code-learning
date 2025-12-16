#include <iostream>

using namespace std;
int a[100][100];
int main() {
	int n,m,num = 1,x=0,y=0,fx = 0 ,f[4][2]= {{1,0},{0,1},{-1,0},{0,-1}};
	cin>>n>>m;
	while (num <= n*m){
		a[x][y] = num++;
		if (x+f[fx][1]<0 || x+f[fx][1] == n || y+f[fx][0] < 0 || y+f[fx][0] == m || a[x+f[fx][1]][y+f[fx][0]] != 0)
			fx = (fx+1)%4;
		x += f[fx][1];
		y += f[fx][0];
	}
	for (int i = 0 ; i < n ; i++) {
		for (int j = 0 ;j < m ;j++)
			printf("%d ",a[i][j]);
		printf("\n");
	}
	return 0;
}
