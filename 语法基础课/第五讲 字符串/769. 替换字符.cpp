#include <iostream>
#include <string>

using namespace std;

int main() {
	string str;
	cin>>str;
	char a;
	cin>>a;
	int l = str.size();
	for (int i = 0 ; i < l ; i++)
		if ( a == str[i]) 
			str[i] = '#';
	cout<<str;
}
