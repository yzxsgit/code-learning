#include<iostream>
#include <cstdio>
#include<string.h>
using namespace std;
int main()
{
	int t,n;
	long long a[100] = {0,1};
	cin>>t;
	for (int i = 2 ; i <= 60 ; i++)
		a[i] = a[i-2] + a[i-1];
	for (int i = 0 ; i < t ; i++)
	{
		cin>>n;
		printf("Fib(%d) = %lld\n",n,a[n]);
	}
	return 0;
}
