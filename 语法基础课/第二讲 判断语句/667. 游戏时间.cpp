#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
	int A,B;
	cin>>A>>B;
	int out = B-A;
	if (out <= 0)
		out += 24;
	printf("O JOGO DUROU %d HORA(S)",out);
	return 0;
}
