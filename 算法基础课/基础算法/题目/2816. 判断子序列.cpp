#include <bits/stdc++.h>

using namespace std;
const int N = 1e5 + 10;
int a[N],b[N];
int n,m;
int main() {
	scanf("%d%d",&n,&m);
	for (int i = 0 ; i < n ; i++)
		scanf("%d",&a[i]);
	for (int i = 0 ; i < m ; i++)
		scanf("%d",&b[i]);
	
	int i = 0 , j = 0;
	while (j < m) {
		if (a[i] == b[j]) i++;
		if (i == n) {
		printf("Yes");
		return 0;
		}
		j++;
	}
	printf("No");
	return 0;
}
