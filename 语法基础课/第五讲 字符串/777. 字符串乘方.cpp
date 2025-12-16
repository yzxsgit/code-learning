#include<iostream>

using namespace std;

int main() {
	string s;
	while (cin>>s,s!=".")
	{
		int len = s.size();
		for (int n = len ; n ; n--)
		{
			if (len%n == 0)
			{
				string a,r=s.substr(0,len/n);
				for (int i = 1; i<=n;i++) a = a + r;
				if (a==s)
				{
					cout<<n<<endl;
					break;
				}
			}
		}
	}
	return 0;
}
