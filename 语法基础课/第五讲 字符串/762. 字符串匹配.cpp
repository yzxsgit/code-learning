#include <iostream>
#include <string.h>

using namespace std;
int main() {
	float k,num = 0;
	string a,b;
	cin>>k>>a>>b;
	int l = a.size();
	for (int i = 0 ; i < l ; i++) if (a[i] == b[i])num++;
	if (num / l >= k) printf("yes");
	else printf("no");
	return 0;
}
