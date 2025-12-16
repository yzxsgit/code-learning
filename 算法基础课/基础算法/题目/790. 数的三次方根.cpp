#include<iostream>
using namespace std;

int main() {
	double n,x;
	scanf("%lf",&n);
	double l = -10000 , r = 10000;
	while (r-l > 1e-8) 
	{
		x = (l+r)/2;
		if (x*x*x >= n) r = x;
		else l = x;
	}
	printf("%.6lf",l);
	return 0;
}
