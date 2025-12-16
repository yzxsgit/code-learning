#include <iostream>
using namespace std;

int walk(int n,int m) {
	if (n == 0 && m == 0)
		return 1;
	else if (n == 0)
		return walk(n,m-1);
	else if (m == 0)
		return walk(n-1,m);
	else 
		return walk(n-1,m) + walk(n,m-1);
}

int main() {
	int n,m;
	cin>>n>>m;
	cout<<walk(n,m);
	return 0;
}
