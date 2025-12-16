#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
	int a[7] = {100,50,20,10,5,2,1};
	int N;
	cin>>N;
	int i = 0;
	printf("%d\n",N);
	while (N!=0||i!=7)
		printf("%d nota(s) de R$ %d,00\n",N/a[i],a[i]),N %= a[i],i++;
	return 0;
}
