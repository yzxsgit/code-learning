#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int N;
	cin>>N;
	for (int i = 1; i <= N ; i++)
		if ( N % i == 0 )
			printf("%d\n",i);
	return 0;
}
