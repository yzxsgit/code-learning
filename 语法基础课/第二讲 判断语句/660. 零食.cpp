#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
float a[5] = {4.00,4.50,5.00,2.00,1.50};
int main(){
	int x,y;
	cin>>x>>y;
	x--;
	printf("Total: R$ %.2f",a[x]*y);
	return 0;
}
