#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int l;
	double M[12][12];
	char a;
	cin>>l>>a;
	for (int i = 0 ; i < 12 ; i++)
		for (int j = 0 ; j < 12 ; j++)
			scanf("%lf",&M[i][j]);
	double out = 0;
	for (int j = 0 ; j < 12 ; j++)
		out += M[l][j];
	if (a == 'M') out/=12;
	printf("%.1lf",out);
	return 0;
}
