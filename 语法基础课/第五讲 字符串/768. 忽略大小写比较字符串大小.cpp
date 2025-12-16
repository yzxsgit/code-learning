#include <iostream>
#include <string.h>

using namespace std;
int main() {
	string a,b;
	getline(cin,a);
	getline(cin,b);
	int n1 = a.size(),n2 = b.size();
	for (int i = 0 ; i < n1 ; i++)
		if (a[i]<='Z' && a[i] >='A')
			a[i] = char(a[i]) - 'A' + 'a';
	for (int i = 0 ; i < n2 ; i++)
		if (b[i]<='Z' && b[i] >='A')
			b[i] = char(b[i]) - 'A' + 'a';
	bool flag = true;
	for (int i = 0 ; i < min(n1,n2) ; i++)
		if (a[i] > b [i]) {
			printf(">");
			flag = false;
			break;
		}
		else if(a[i] < b[i]) {
			printf("<");
			flag = false;
			break;
		}
	if (flag){
		if (n1 == n2)
			printf("=");
		else if (n1 > n2)
			printf(">");
		else
			printf("<");
	}
	return 0;
}
