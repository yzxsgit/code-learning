#include <iostream>
using namespace std;

void print(int a[] , int size) {
	for (int i = 0 ; i < size ; i++)
		cout<<a[i]<<' ';
}

int main() {
	int a[1000],n,size;
	cin>>n>>size;
	for (int i = 0 ; i < n ; i++)
		cin>>a[i];
	print(a,size);
	return 0;
}
