#include <iostream>
#include <string>
using namespace std;

int main() {
	string str;
	getline(cin,str);
	int a = str.size(),num = 0;
	for (int i = 0 ; i < a ;i++)
		if ( str[i] >=48 && str[i] <= 57)
			num++;
	cout<<num<<endl;
	return 0;
} 
