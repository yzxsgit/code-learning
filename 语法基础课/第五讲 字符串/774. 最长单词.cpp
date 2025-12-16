#include <iostream>
#include <sstream>

using namespace std;

int main() {
	string s,out;
	getline(cin,s);
	
	stringstream ssin(s);
	string str;
	int a=0,b;
	while (ssin>>str)
	{
		b = str.size();
		if (str[b-1] == '.'){
			b--;
			str[b] = ' ';
		}
		if (b > a){
			out = str;
			a = b;
		}
	}
	cout<<out;
	return 0;
}
