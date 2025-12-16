#include <bits/stdc++.h>

using namespace std;

vector<int> alls;
//二分查位置 
int find(int x) {
	int l = 0 , r = alls.size()-1;
	while (l < r) {
		int mid = l + r >> 1;
		if (alls[mid] >= x) r = mid;
		else l = mid + 1;
	}
	return r + 1;
}

int main() {
	int n,res;
	scanf("%d",&n);
	while(n--) scanf("%d",&res),alls.push_back(res);
	
	sort(alls.begin(),alls.end());//排序 
	alls.erase(unique(alls.begin(),alls.end()),alls.end());//去重 
	
	scanf("%d",&res);
	
	res = find(res);
	printf("%d",res);
	return 0 ;
}
