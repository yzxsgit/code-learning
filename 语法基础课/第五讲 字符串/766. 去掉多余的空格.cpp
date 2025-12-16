#include <iostream>
#include <string.h>

using namespace std;
int main() {
	string a,b;
	getline(cin,a);
	bool flag = true;
	int n = a.size();
	for (int i = 0 ; i < n ; i++)
	{
//		cout<<int(a[i])<<' ';
		if (int(a[i]) == 32)
		{
//			cout<<i<<" ";
			if (flag) {
				b = b + a[i];
				flag = false;
			}
		}
		else{
			b = b + a[i];
			flag = true;
		}
	}
	cout<<b;
	return 0;
}
