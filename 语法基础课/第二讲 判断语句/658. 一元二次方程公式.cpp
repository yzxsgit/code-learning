#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main() {
	double a,b,c;
	cin>>a>>b>>c;
	if (a == 0 || b*b-4*a*c < 0)
		printf("Impossivel calcular");
	else
	{
		double delta = sqrt(b*b-4*a*c);
		double x1,x2;
		x1 = (-b+delta)/(2*a);
		x2 = (-b-delta)/(2*a);
		printf("R1 = %.5lf\nR2 = %.5lf",x1,x2);
	}
	return 0;
}
