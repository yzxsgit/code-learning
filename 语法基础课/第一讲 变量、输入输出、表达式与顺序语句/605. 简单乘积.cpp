#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
	int num1,num2,item1,item2;
	double price1,price2;
	cin>>num1>>item1>>price1;
	cin>>num2>>item2>>price2;
	printf("VALOR A PAGAR: R$ %.2lf",item1*price1+item2*price2);
	return 0;
}
