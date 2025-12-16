#include<iostream>
#include<string.h>
using namespace std;
int main()
{
	char a[30000];
	int top = 0,out = 0,st[30000],maxx = 0;
	bool flag = true,b[30000];
	cin>>a;
	int l = strlen(a);
	for (int i = 0 ; i < l ; i++) {
		if (a[i] == 40) {
			st[top++] = i;
		}
		else if ( top > 0 ) {
			b[st[--top]] = 1;
			b[i] = 1;
		}
	}
	for (int i = 0 ; i < l ; i++) {
		if (b[i]) out++;
		else {
			maxx = max(maxx,out);
			out = 0;
		}
	}
	printf("%d",max(maxx,out));
	return 0;
}
