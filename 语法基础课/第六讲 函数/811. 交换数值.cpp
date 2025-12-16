#include <iostream>
using namespace std;

void swap(int &x, int &y) {
	int a;
	a = x;
	x = y;
	y = a;
}

int main() {
	int x , y;
	cin>>x>>y;
	swap(x,y);
	cout<<x<<' '<<y;
	return 0;
}
