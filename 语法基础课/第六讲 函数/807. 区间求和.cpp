#include <iostream>
using namespace std;

int sum(int l,int r) {
	int num = 0;
	while (l <= r)
		num += l++;
	return num;
}

int main() {
	int l,r;
	cin>>l>>r;
	cout<<sum(l,r);
	return 0;
}
