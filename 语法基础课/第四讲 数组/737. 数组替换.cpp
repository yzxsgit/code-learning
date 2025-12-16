#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int x[10];
	for (int i = 0 ; i <= 9 ; i++) {
		cin>>x[i]; 
		if ( x[i] <= 0 ) x[i] = 1;
		printf("X[%d] = %d\n",i,x[i]);
	}
	return 0;
}
