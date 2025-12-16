#include <iostream>
#include <string.h>

using namespace std;
int count[26];
int main() {
	string a;
	cin>>a;
	int l = a.size(),wz = 1e9;
	for (int i = 0 ; i < l ; i++) count[int(a[i])-97]++;
	bool flag = true;
	for (int i = 0 ; i <=l ; i++)
	{
		if (count[a[i]-97] == 1)
		{
			cout<<a[i]<<endl;
			flag = false;
			break;
		}
	}
//	cout<<wz<<endl;
	if (flag) cout<<"no"<<endl;
	return 0;
}
