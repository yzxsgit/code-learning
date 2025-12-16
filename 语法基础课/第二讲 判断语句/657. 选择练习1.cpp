#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main() {
	int A,B,C,D;
	cin>>A>>B>>C>>D;
	if (B>C && D>A && C+D>A+B && C>0 && D>0 && A%2==0)
		printf("Valores aceitos");
	else printf("Valores nao aceitos");
	return 0;
}
