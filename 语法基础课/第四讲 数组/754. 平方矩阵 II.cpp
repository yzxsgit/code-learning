#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int n[100][100],N;
	cin>>N;
	while (N != 0) {
		for (int i = 1 ; i <= N; i++) {
			for (int j = 1 ; j <= N ; j++)
				printf("%d ",N-min(abs(i-1)+abs(j-N),abs(i-N)+abs(j-1)));
			printf("\n");
			}
		printf("\n");
		cin>>N;
	}
	return 0; 
}
