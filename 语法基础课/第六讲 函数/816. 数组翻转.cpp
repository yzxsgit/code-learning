#include <iostream> 
using namespace std;

void reverse(int *a , int size) {
	int i = 0 ,j = size-1;
	while (i < j) {
		swap(a[i],a[j]);
		i++;
		j--;
	}
	return;
}

int main() {
	int n,size;
	cin>>n>>size;
	int a[n];
	for (int i = 0 ; i < n ; i++)
		cin>>a[i];
	reverse(a,size);
	for (int i = 0 ; i < n ; i++)
		cout<<a[i]<<' ';
	return 0;
}
