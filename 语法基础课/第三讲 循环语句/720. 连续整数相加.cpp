#include <iostream>
using namespace std;
int main() {
	int A , N ;
	cin>>A>>N;
	while ( N <= 0)
		cin>>N;
	printf("%d",(A+A+N-1)*N/2);
	return 0;
}
