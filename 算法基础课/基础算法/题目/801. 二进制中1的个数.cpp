#include <bits/stdc++.h>
using namespace std;
int main(){
	int n;
	scanf("%d",&n);
	while (n--)
	{
		int a,num = 0;
		scanf("%d",&a);
		while (a) {
			a -= (a&(-a));
			num++;
		}
		printf("%d ",num);
	}
	return 0;
}
