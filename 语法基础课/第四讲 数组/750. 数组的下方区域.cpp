#include <iostream>
#include <math.h>
using namespace std;
int main() {
	double m[12][12],out=0;
	char a;
	int num = 0;
	cin>>a;
	for (int i = 0 ; i < 12 ; i++)
		for (int j = 0 ; j < 12 ; j++)
			cin>>m[i][j];
	for (int i = 0 ; i < 12 ; i++)
		for (int j = 0 ; j < 12 ; j++)
			if (abs(i-11)+abs(j-0) < 11 && abs(i-11)+abs(j-11) < 11){
				num++;
				out += m[i][j];
			}
	if (a == 'M')
		out /= num;
	printf("%.1lf",out);
	return 0; 
}
