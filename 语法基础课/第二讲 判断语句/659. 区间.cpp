#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
	float x;
	cin>>x;
	if (x>100 || x<0)
		printf("Intervalo x");
	else if (x>50)
		if (x>75)
			printf("Intervalo (75,100]");
		else
			printf("Intervalo (50,75]");
	else if (x>25)
			printf("Intervalo (25,50]");
		else
			printf("Intervalo [0,25]");
	return 0;
}
