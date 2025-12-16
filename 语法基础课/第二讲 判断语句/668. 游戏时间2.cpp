#include <iostream>
using namespace std;
int main() {
	int A,B,C,D,X,Y;
	cin>>A>>B>>C>>D;
	if  ( C < A || C == A && D<=B) C += 24;
	Y = (C-A)*60+D-B;
	X = Y/60;
	Y = Y%60;
	printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)",X,Y);
	return 0;
}
