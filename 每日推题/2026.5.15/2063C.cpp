#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <functional>
#include <array>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

struct cmp
{
    bool operator()(PII x, PII y) const
    {
        return x.first < y.first;
    }
};

void solve()
{
    int n;
    cin >> n;

    vector<int> d(n + 1, 0);
    vector<vector<int>> adj(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        d[u]++;
        d[v]++;
    }

    multiset<int> s;

    for (int i = 1; i <= n; i++)
        s.insert(d[i]);

    int ans = 0;

    for (int u = 1; u <= n; u++)
    {
        int du = d[u];

        s.erase(s.find(d[u]));

        for (int v : adj[u])
        {
            s.erase(s.find(d[v]));
            d[v]--;
            s.insert(d[v]);
        }

        if (!s.empty())
        {
            ans = max(ans, du + *s.rbegin() - 1);
        }

        for (int v : adj[u])
        {
            s.erase(s.find(d[v]));
            d[v]++;
            s.insert(d[v]);
        }

        s.insert(d[u]);
    }

    cout << ans << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}