#include <iostream>
#include <string>

using namespace std;

int main() {
	string a,b;
	cin>>a>>b;
	if (a.size()<b.size())
		swap(a,b);
	a = a+a;
	int c = a.find(b);
	if(c!=-1)
		printf("true");
	else
		printf("false");
	return 0;
}
