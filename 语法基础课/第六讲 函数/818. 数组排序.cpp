#include <iostream>
using namespace std;

void sort(int *a , int l ,int r) {
	for (int i = l ; i <= r ; i++)
		for (int j = i ;j <= r ; j++)
			if (a[i] > a[j])
				swap(a[i],a[j]);
}

int main() {
	int n,l,r;
	cin>>n>>l>>r;
	int b[n];
	for (int i = 0 ; i < n ; i++)
		cin>>b[i];
	sort(b,l,r);
	for (int i = 0 ; i < n ; i++)
		cout<<b[i]<<' ';
	return 0;
}
