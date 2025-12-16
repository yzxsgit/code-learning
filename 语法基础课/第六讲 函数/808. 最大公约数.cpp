#include <iostream>
using namespace std;

int gad(int a,int b) {
	if(a % b == 0)
		return b;
	else return gad(b,a%b);
}

int main() {
	int a,b;
	cin>>a>>b;
	cout<<gad(a,b);
}
