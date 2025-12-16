#include <iostream>
#include <string>

using namespace std;

int main() {
	string a,b;
	while (cin>>a>>b) {
		int l = a.size() , flag = 0;
		for (int i = 1 ; i < l ; i++) 
			if (a[flag] < a[i])
				flag = i;
		string c;
		for (int i = 0 ; i <= flag ; i++)
			c = c + a[i];
		c = c + b;
		for (int i = flag+1 ; i < l ; i++)
			c = c + a[i];
		cout<<c<<endl;
	}	
	return 0;
}
