#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int X;
	cin>>X;
	X = X+(X+1)%2;
	for ( int i = 1 ; i <= 6 ; i++ ) {
		printf("%d\n",X);
		X+=2;
	}
	return 0;
}
