#include <iostream>
using namespace std;

int get_unique_count(int *a, int n){
	int b[1001],num = 0;
	for (int i = 1 ; i <= 1000 ; i++)
		b[i] = 0 ;
	for (int i = 0 ; i < n ; i++)
		b[a[i]]++;
	for (int i = 1 ; i <= 1000 ; i++)
		if (b[i] > 0)
			num++;
	return num;
}

int main(){
	int n;
	cin>>n;
	int c[n];
	for (int i = 0 ; i < n ; i++)
		cin>>c[i];
	cout<<get_unique_count(c,n);
	return 0;
}

