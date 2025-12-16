#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int N;
	cin>>N;
	for (int i = 1 ; i <= 10 ; i++)
		printf("%d x %d = %d\n",i,N,i*N);
	return 0;
}
