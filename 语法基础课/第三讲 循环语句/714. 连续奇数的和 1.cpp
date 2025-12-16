#include <iostream>
using namespace std;
int main() {
	int X,Y,num = 0 ;
	cin>>X>>Y;
	if ( X > Y ) swap(X,Y);
	if ( X%2 == 0) X--;
	for ( int i = X+2 ; i<Y ; i+=2)
		num+=i;
	printf("%d",num);
	return 0;
}
