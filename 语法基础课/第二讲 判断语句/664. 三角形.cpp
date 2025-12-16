#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
	float A,B,C;
	cin>>A>>B>>C;
	if (A+B>C && A+C>B && B+C>A)
		printf("Perimetro = %.1f",A+B+C);
	else
		printf("Area = %.1f",(A+B)*C/2);
	return 0;
}
