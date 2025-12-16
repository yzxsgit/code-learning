#include<iostream>
#include <cstdio>
#include<string.h>
using namespace std;
int main()
{
	int N,X[1000];
	cin>>N;
	for (int i = 0 ; i < N ; i++)
		cin>>X[i];
	int num = 0 ;
	for (int i = 1 ; i < N ; i++)
		if (X[num] > X[i])
			num = i;
	printf("Minimum value: %d\nPosition: %d",X[num],num);
	return 0;
}
