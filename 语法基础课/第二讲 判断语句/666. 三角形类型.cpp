#include <iostream>
using namespace std;
int main() {
	float A,B,C;
	cin>>A>>B>>C;
	if (A < B) swap(A,B);
	if (A < C) swap(A,C);
	if (B < C) swap(B,C);
	if (A >= B+C)
		printf("NAO FORMA TRIANGULO\n");
	else 
		if (A*A==B*B+C*C)
			printf("TRIANGULO RETANGULO\n");
		else if (A*A>B*B+C*C)
			printf("TRIANGULO OBTUSANGULO\n");
		else if (A*A<B*B+C*C) 
			printf("TRIANGULO ACUTANGULO\n");
		if (A == B && B == C)
			printf("TRIANGULO EQUILATERO\n");
		else if (A == B || B == C || A == C)
			printf("TRIANGULO ISOSCELES\n");
	return 0;
}
