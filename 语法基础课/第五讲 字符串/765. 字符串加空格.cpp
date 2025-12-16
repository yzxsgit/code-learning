#include <iostream>
#include <string>

using namespace std;
char b[300];
int main() {
	string a;
	getline(cin,a);
	int l = a.size();
	for (int i = 0 ; i < l ; i++) {
		b[i*2] = a[i] ; 
		b[i*2+1] = ' ';
	}
	cout<<b<<endl;
}
