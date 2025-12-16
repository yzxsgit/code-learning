#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int n[10];
	cin>>n[0];
	printf("N[0] = %d\n",n[0]);
	for (int i = 1;i <= 9; i++){
		n[i] = n[i-1] *2;
		printf("N[%d] = %d\n",i,n[i]);
	}
	return 0;
}
