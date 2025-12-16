#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
	int a,b,c;
	cin>>a>>b>>c;
	printf("%d eh o maior",max(max(a,b),c));
	return 0;
}
