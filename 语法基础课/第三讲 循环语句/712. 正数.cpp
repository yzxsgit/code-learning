#include <iostream>
using namespace std;
int main() {
	float a;
	int i = 0 ,num = 0;
	while ( i<=5 ) {
		cin>>a;
		if ( a>0 ) num++;
		i++;
	}
	printf("%d positive numbers",num);
	return 0;
}
