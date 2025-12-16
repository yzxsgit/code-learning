#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int N , x = 0 , y = 1;
	cin>>N;
	for (int i = 1 ; i <= N ; i++){
		printf("%d ",x);
		int a = y;
		y += x;
		x = a;
	}
	return 0;
}
