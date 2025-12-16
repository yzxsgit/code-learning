#include<iostream>
#include <cstdio>
using namespace std;
int main(){
	int num,time;
	double salary;
	cin>>num>>time>>salary;
	printf("NUMBER = %d\nSALARY = U$ %.2lf",num,time*salary);
	return 0;
}
