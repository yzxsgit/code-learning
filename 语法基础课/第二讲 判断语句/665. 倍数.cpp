#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
	int A,B;
	cin>>A>>B;
	int a = (A+B+abs(A-B))/2 , b = (A+B-abs(A-B))/2;
	if (a%b == 0)
		printf("Sao Multiplos");
	else printf("Nao sao Multiplos");
	return 0;
}
