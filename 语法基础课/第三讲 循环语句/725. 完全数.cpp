#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int N;
	cin>>N;
	for (int i = 1 ; i <= N ; i++) {
		int M,num = 1;
		bool flag = true; 
		scanf("%d",&M);
		for (int j = 2 ; j <= sqrt(M); j++)
		{
			if ( M % j == 0 ) {
				if ( j < M ) num += j;
				if ( j != M / j) num += M / j;
			}
			if ( num > M ) {
				flag = false;
				break;
			}
		}
		if ( flag && num != 1) { 
			if ( num == M ) {
				printf("%d is perfect\n",num);
				continue;
			}
		}
		printf("%d is not perfect\n",M);
	}
	return 0;
}
