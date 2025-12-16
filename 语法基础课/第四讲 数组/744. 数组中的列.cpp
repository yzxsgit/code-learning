#include <iostream>
using namespace std;
int main() {
	double m[12][12],out=0;
	int l;
	char a;
	cin>>l>>a;
	for (int i = 0 ; i < 12 ; i++)
		for (int j = 0 ; j < 12 ; j++)
			cin>>m[i][j];
	for (int i = 0 ; i < 12 ; i++)
		out += m[i][l];
	if (a == 'M')
		out /= 12;
	printf("%.1lf",out);
	return 0; 
}
