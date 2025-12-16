#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
	float salary;
	cin >> salary;
	if ( salary <= 400 )
		printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 15 %%",salary*1.15,salary*0.15);
	else if ( salary <= 800 )
		printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 12 %%",salary*1.12,salary*0.12);
	else if ( salary <= 1200 )
		printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 10 %%",salary*1.10,salary*0.1);
	else if ( salary <= 2000 )
		printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 7 %%",salary*1.07,salary*0.07);
    else
		printf("Novo salario: %.2f\nReajuste ganho: %.2f\nEm percentual: 4 %%",salary*1.04,salary*0.04);			
	return 0;
}
