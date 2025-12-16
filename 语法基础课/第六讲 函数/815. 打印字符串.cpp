#include <iostream>
#include <string.h>
using namespace std;

void print (char str[]) {
	int n = strlen(str);
	for (int i = 0 ; i < n ; i++)
		cout<<str[i];
	return;
}

int main() {
	char str[101];
	fgets(str,101,stdin);
	print(str);
	return 0;
}
