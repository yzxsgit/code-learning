#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int M,N;
	cin>>M>>N;
	while ( M > 0 && N > 0 ) {
		if ( M > N ) swap(M,N);
		int num = 0;
		for (int i = M; i <= N ; i++ ) {
			num += i;
			printf("%d ",i);
		}
		printf("Sum=%d\n",num);
		cin>>N>>M;
	}
	return 0;
}
