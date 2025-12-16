#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int N,C = 0,R = 0,F = 0;
	float A = 0;
	cin>>N;
	for (int i = 1 ; i <= N ; i++) {
		int x;
		char y;
		cin>>x>>y;
		if (y == 'C') C += x;
		else if (y == 'R') R += x;
		else F += x;
		A += x;
	}
	printf("Total: %d animals\nTotal coneys: %d\nTotal rats: %d\nTotal frogs: %d\nPercentage of coneys: %.2f %%\nPercentage of rats: %.2f %%\nPercentage of frogs: %.2f %%",int(A),C,R,F,C/A*100,R/A*100,F/A*100);
	return 0;
}
