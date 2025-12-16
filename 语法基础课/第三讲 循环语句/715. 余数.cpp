#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int N ;
	cin>>N;
	for (int i = 2 ; i < 10000 ; i++ )
		if ( i % N == 2 )
			printf("%d\n",i);
	return 0;
}
