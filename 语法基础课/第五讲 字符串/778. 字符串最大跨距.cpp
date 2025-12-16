#include<iostream>

using namespace std;

int main() {
	string s1,s2,s3;
	getline(cin,s1);
	int len = s1.size(),a = s1.find(",") , b = s1.rfind(",");
	for (int i = a+1 ; i < b ; i++)
		s2 = s2+s1[i];
	for (int i = b+1 ; i < len ; i++)
		s3 = s3+s1[i];
	s1.erase(a);
	a = s1.size() , b = s2.size() ;
	int c = s3.size();
	if(a<b || a<c) cout<<-1<<endl;
	else {
		int l = 0;
		while (l+b<a){
			int k = 0;
			while (k < b) {
				if (s1[l+k]!=s2[k]) break;
				k++;
			}
			if (k == b) break;
			l++;
		}
		int r = a-1;
		while (r>=0){
			int k = 0;
			while (k < c) {
				if (s1[r+k]!=s3[k]) break;
				k++;
			}
			if (k == c) break;
			r--;
		}
		
		l += b-1;
		if (l >= r) puts("-1");
		else cout<<r-l-1<<endl;
	}
	return 0;
}
