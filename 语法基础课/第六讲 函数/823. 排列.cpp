#include<iostream>
using namespace std;

bool pd[10];
int n,num[10];
void print(int c) {
	if (c == 0)
	{
		for (int i = 0 ; i < n ; i++)
			cout<<num[i]<<' ';
		cout<<endl;
		return;
	}
	else 
		for (int i = 1 ; i <= n ; i++)
		{
			if (!pd[i])
			{
				pd[i] = true;
				num[n-c] = i;
				print(c-1);
				pd[i] = false;
			}
		}
}
int main() {
	cin>>n;
	print(n);
	return 0;
}
