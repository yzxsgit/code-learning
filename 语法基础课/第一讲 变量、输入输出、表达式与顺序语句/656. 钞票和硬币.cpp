#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
	double a[12] = {100.00,50.00,20.00,10.00,5.00,2.00,1.00,0.50,0.25,0.10,0.05,0.010};
	double N;
	cin>>N;
	int i = 0;
	printf("NOTAS:\n");
	while (i<6){
		printf("%d nota(s) de R$ %.2f\n",int(N/a[i]),a[i]);
		N -=a[i]*int(N/a[i]);
		i++;
		}
	N = N*(1.00001);
	printf("MOEDAS:\n");
	while (i<12){
		printf("%d moeda(s) de R$ %.2f\n",int(N/a[i]),a[i]);
		N -=a[i]*int(N/a[i]);
		i++;
		}
	return 0;
}
