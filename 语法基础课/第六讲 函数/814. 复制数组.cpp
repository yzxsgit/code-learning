#include <iostream>
using namespace std;

void copy(int a[] , int *b , int size) {
	for (int i = 0 ; i < size ; i++)
		b[i]  = a[i];
	return;
}
int main() {
	int n,m,size;
	cin>>n>>m>>size;
	int a[n],b[m];
	for (int i = 0 ; i < n ; i++)
		cin>>a[i];
	for (int i = 0 ; i < m ; i++)
		cin>>b[i];
	copy(a,b,size);
	for (int j = 0 ; j < m ; j++)
		cout<<b[j]<<' ';
	return 0;
}
