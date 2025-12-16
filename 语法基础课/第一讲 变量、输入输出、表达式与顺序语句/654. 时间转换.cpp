#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
	int N,hours,minutes,seconds;
	cin>>N;
	hours = N/3600;
	minutes = N%3600/60;
	seconds = N%60;
	printf("%d:%d:%d",hours,minutes,seconds);
	return 0;
}
