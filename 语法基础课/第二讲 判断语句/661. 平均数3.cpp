#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main() {
	float N1,N2,N3,N4;
	cin>>N1>>N2>>N3>>N4;
	float X = (N1*2+N2*3+N3*4+N4)/10;
	printf("Media: %f\n",X);
	if ( X >= 7.0 ) printf("Aluno aprovado.\n");
	else if (X < 5.0) printf("Aluno reprovado.\n");
	else{
		printf("Aluno em exame.\n");
		float Y;
		cin>>Y;
		printf("Nota do exame: %f\n",Y);
		float Z = X+Y;
		if ( Z >= 10 ) printf("Aluno aprovado.\n");
		else printf("Aluno reprovado.\n");
		printf("Media final: %f",Z/2);
	}
	return 0;
}
