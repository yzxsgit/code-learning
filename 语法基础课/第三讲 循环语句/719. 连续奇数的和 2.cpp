#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int N;
	cin>>N;
	for (int i = 1 ; i <= N ;i++) {
		int X,Y,num = 0 ;
		cin>>X>>Y;
		if ( X > Y ) swap(X,Y);
		if ( X%2 == 0) X--;
		for ( int i = X+2 ; i<Y ; i+=2)	num+=i;
		printf("%d\n",num);
	}
	return 0;
}
