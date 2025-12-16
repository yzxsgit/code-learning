#include <iostream>
#include <math.h>
using namespace std;
int main() {
	double M[12][12];
	char a;
	cin>>a;
	for (int i = 0 ; i < 12 ; i++)
		for (int j = 0 ; j < 12 ; j++)
			scanf("%lf",&M[i][j]);
	double out = 0 , num = 0;
	for (int i = 0 ; i < 12 ; i++)
		for (int j = 0 ; j < 12 ; j++)
			if (abs(i-0)+abs(j-11) < 11 ){
				num++;
				out += M[i][j];
			}
	if (a == 'M') out/=num;
	printf("%.1lf",out);
	return 0;
}
