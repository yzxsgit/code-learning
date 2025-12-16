#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
	int N;
	cin>>N;
	printf("%d ano(s)\n%d mes(es)\n%d dia(s)",N/365,N%365/30,N%365%30);
	return 0;
}
