#include <iostream>
using namespace std;
int main() {
	int x,y=-1e9,wz,i = 0;
	while ( i < 100 ) {
		cin>>x;
		if ( x > y ) {
			wz = i+1;
			y = x;
		}
		i++;
	}
	printf("%d\n%d",y,wz);
	return 0;
}
