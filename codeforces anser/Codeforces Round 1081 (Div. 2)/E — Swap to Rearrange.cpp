#include <bits/stdc++.h>
using namespace std;

int a[1000005];
int b[1000005];
vector<pair<int,int>> adj[1000005];
bool vst[1000005];
bool ans[1000005];
 
void dfs(int node) {
	while (adj[node].size()) {
		auto [it,w] = adj[node].back();
		adj[node].pop_back();
		if (vst[w])continue;
		vst[w] = true;
		// brick(node);brick(it);dbg(w);
		dfs(it);
		if (node == a[w])ans[w] = true;
		else ans[w] = false;
	}
	return;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int tt;
	cin >> tt;
	while (tt--) {
		int n;
		cin >> n;
		for (int i = 1; i <= n; ++i) {
			cin >> a[i];
		}
		for (int i = 1; i <= n; ++i) {
			cin >> b[i];
		}
		for (int i = 1; i <= n; ++i) {
			adj[i].clear();
			vst[i] = false;
		}
		for (int i = 1; i <= n; ++i) {
			adj[a[i]].emplace_back(b[i],i);
			adj[b[i]].emplace_back(a[i],i);
		}
		bool check = true;
		for (int i = 1; i <= n; ++i) {
			if (adj[i].size()&1)check = false;
		}
		if (!check) {
			cout << -1 << '\n';
			continue;
		}
		for (int i = 1; i <= n; ++i) {
			dfs(i);
		}
		vector<int> res;
		for (int i = 1; i <= n; ++i) {
			if (ans[i])res.push_back(i);
		}
		cout << res.size() << '\n';
		for (auto it : res) {
			cout << it << ' ';
		} cout << '\n';
	}
	return 0;
}