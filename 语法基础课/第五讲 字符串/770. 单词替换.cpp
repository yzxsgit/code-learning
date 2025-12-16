#include <iostream>
#include <sstream>

using namespace std;

int main() {
	string a,b,c;
	getline(cin,a);
	cin>>b>>c;
	
	stringstream ssin(a);
	string s;
	while (ssin>>s)
		if (s == b) cout<<c<<' ';
		else cout<<s<<' ';
	return 0;
}
