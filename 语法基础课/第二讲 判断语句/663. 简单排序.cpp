#include <iostream>
using namespace std;
int main() {
	int a,b,c;
	cin>>a>>b>>c;
	int A = max(a,max(b,c)), C = min(a,min(b,c)) ,B = a+b+c-A-C;
	printf("%d\n%d\n%d\n\n%d\n%d\n%d",C,B,A,a,b,c);
	return 0;
}
