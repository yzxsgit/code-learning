#include <iostream>
using namespace std;

int Fib(int n) {
	if (n == 1 || n == 2)
		return 1;
	else 
		return Fib(n-2)+Fib(n-1);
}

int main() {
	int n;
	cin>>n;
	cout<<Fib(n);
	return 0;
}
