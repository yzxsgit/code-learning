#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int n;
	cin>>n;
	while (n != 0) {
		for (int i = 1 ; i <= n ; i++){
			for (int j = 1 ; j <= n ; j++) {
				printf("%d ",1+min(min(i-1,n-i),min(j-1,n-j)));
			}
			printf("\n");
		}
		printf("\n");
		cin>>n;
	}
	return 0;
}
