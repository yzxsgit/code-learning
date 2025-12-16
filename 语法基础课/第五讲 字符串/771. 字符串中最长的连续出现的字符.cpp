#include <iostream>
#include <string.h>

using namespace std;

int main() {
	int n;
	cin>>n;
	while (n--) {
		string s;
		cin>>s;
		int num = 1,out = 0;
		char a = s[0],b;
		for (int i = 1 ; i < s.size() ; i++ )
			if (a == s[i])
				num++;
			else if (num > out){
				out = num;
				num = 1;
				b = a;
				a = s[i];
			}
			else num = 1 ,a = s[i];
		if (num > out){
				out = num;
				num = 1;
				b = a;
		}
		else num = 1;
		cout<<b<<' '<<out<<endl;
	}
	return 0;
}
