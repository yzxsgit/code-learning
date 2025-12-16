#include <iostream>
#include <cmath>
using namespace std;
int main() {
	int n[100][100],N;
	cin>>N;
	while (N != 0) {
		for (int i = 0 ; i < N; i++) {
			for (int j = 0 ; j < N ; j++){
				int out = pow(2,i+j);
				printf("%d ",out);
			}
			printf("\n");
			}
		printf("\n");
		cin>>N;
	}
	return 0; 
}
