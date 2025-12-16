#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int N , M ; 
	cin>>N>>M;
	for (int i = 0 ; i < N  ; i++) {
		for (int j = 1 ; j < M ; j++)
			printf("%d ",i*M+j );
		printf("PUM\n");
		}
	return 0;
}
