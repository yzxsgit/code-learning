#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
	string name;
	cin>>name;
	double base,bonus;
	cin>>base>>bonus;
	printf("TOTAL = R$ %.2lf",base+bonus*0.15);
	return 0;
}
