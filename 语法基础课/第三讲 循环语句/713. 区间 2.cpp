#include <iostream>
#include <math.h>
using namespace std;
int main() {
	int N , x , in = 0 ,out = 0;
	cin >> N;
	for (int i = 1 ; i <= N ; i++) {
		cin>>x;
		if (10 <= x && x <= 20)
			in++;
		else out++;
	}
	printf("%d in\n%d out",in,out);
	return 0;
}
