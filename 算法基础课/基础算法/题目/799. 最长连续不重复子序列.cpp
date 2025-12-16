#include <bits/stdc++.h>

using namespace std;
const int N = 1e6 + 10;
int a[N];
int n,ans;
bool flag[N];
int main() {
	scanf("%d",&n);
	for (int i = 0 ; i < n ; i++)
		scanf("%d",&a[i]);
	
	for (int i = 0 , j = 0 ; j < n ;) {
		while (!flag[a[j]] && j < n)	flag[a[j++]] = true;
		ans = max(ans,j-i);
		while (flag[a[j]] && i <= j) flag[a[i++]] = false;
	}
	printf("%d",ans);
	return 0;
} 
// 9 3 6 9 5 10 1 2 3 9
