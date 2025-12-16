#include<iostream>

using namespace std;

int main() {
	int n;
	while (cin>>n,n!=0)
	{
		string str[n];
		int len[n],mlen=0xffffff;
		for (int i = 0 ; i < n ;i++) {
			cin>>str[i];
			len[i] = str[i].size();
			mlen = min(len[i],mlen);
		}
		string same;
		bool flag = true;
		for (int i = 0 ; i < mlen ; i++) {
			for (int j = 1 ; j < n ; j++)
				if (str[0][len[0]-1-i] != str[j][len[j]-1-i]){
					flag = false;
					break;
				}
			if (flag)
				same = str[0][len[0]-1-i] + same;
			else
				break;
		}
		cout<<same<<endl;
	}
	return 0;
}
