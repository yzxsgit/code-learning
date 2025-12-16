#include <iostream>
#include <string.h>

using namespace std;

int main() {
	string a,b;
	getline(cin,a);
	for (int i = 0 ; i < a.size()-1 ; i++)
		b += char(a[i])+char(a[i+1]);
	b += char(a[0])+char(a[a.size()-1]);
	cout<<b;
	return 0;
}
