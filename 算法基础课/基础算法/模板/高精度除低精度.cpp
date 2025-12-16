#include <bits/stdc++.h>

using namespace std;

vector<int> div (vector<int> A , int b , int &r) {
	vector<int> C;
	
	for (int i = A.size()-1 ; i >= 0 ; i--) {
		r = r * 10 + A[i];
		C.push_back(r / b);
		r = r % b ;
	}
	reverse(C.begin(),C.end());
	while (C.size() > 1 && C.back() == 0) C.pop_back();
	
	return C;
}

int main() {
	vector<int> A;
	string a;
	int b,r = 0;
	cin>>a>>b;
	for (int i = a.size()-1 ; i >= 0 ; i--) A.push_back(a[i]-'0');
	
	vector<int> C = div(A,b,r);
	
	for (int i = C.size()-1 ; i >= 0 ; i--) printf("%d",C[i]);
	printf("\n%d\n",r);
	
	return 0;
}
