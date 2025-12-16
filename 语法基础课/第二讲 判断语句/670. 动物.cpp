#include <iostream>
#include <cstdio>
#include <math.h>
using namespace std;
int main(){
	string a,b,c;
	cin>>a>>b>>c;
	if (a == "vertebrado")
		if (b == "ave")
			if (c == "carnivoro")
				printf("aguia");
			else
				printf("pomba");
		else if (c == "onivoro")
			printf("homem");
		else 
			printf("vaca");
	else
		if (b == "inseto")
			if (c == "hematofago")
				printf("pulga");
			else
				printf("lagarta");
		else if (c == "hematofago")
			printf("sanguessuga");
		else 
			printf("minhoca");
	return 0;
}
