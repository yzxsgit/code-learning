#include <iostream>
#include <string.h>

using namespace std;

int main() {
	string a;
	getline(cin,a);
	for (int i = 0 ; i < a.size() ; i++)
		if (a[i] >= 'a' && a[i] <= 'z' )
			a[i] = char((a[i]-'a'+1)%26+'a');
		else if ( a[i] <= 'Z' && a[i] >= 'A')
			a[i] = char((a[i]-'A'+1)%26+'A');
	cout<<a;
	return 0;
}
