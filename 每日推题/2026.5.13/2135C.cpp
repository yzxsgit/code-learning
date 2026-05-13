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

const int mod = 998244353;

void solve()
{
    int n, m, V;
    cin >> n >> m >> V;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    vector<vector<int>> adj(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    vector<int> dfn(n + 1), low(n + 1), bel(n + 1);
    vector<int> stk;
    vector<vector<int>> dcc;

    int idx = 0;

    function<void(int, int)> tarjan = [&](int u, int fa) -> void
    {
        dfn[u] = low[u] = ++idx;
        stk.push_back(u);

        for (auto v : adj[u])
        {
            if (!dfn[v])
            {
                tarjan(v, u);
                low[u] = min(low[u], low[v]);
            }
            else if (fa != v)
            {
                low[u] = min(low[u], dfn[v]);
            }
        }

        if (dfn[u] == low[u])
        {
            int id = dcc.size();
            dcc.push_back({});

            while (true)
            {
                int x = stk.back();
                stk.pop_back();

                bel[x] = id;
                dcc[id].push_back(x);

                if (x == u)
                    break;
            }
        }
    };

    for (int i = 1; i <= n; i++)
    {
        if (!dfn[i])
            tarjan(i, 0);
    }

    vector<int> col(n + 1, -1);

    function<bool(int, int, int)> dfs = [&](int u, int c, int id) -> bool
    {
        if (col[u] != -1)
            return col[u] == c;

        col[u] = c;

        for (int v : adj[u])
        {
            if (bel[v] != id)
                continue;

            if (!dfs(v, c ^ 1, id))
                return false;
        }

        return true;
    };

    i64 ans = 1;

    for (int id = 0; id < dcc.size(); id++)
    {
        int x = -1;

        for (int u : dcc[id])
        {
            if (a[u] == -1)
                continue;

            if (x == -1)
            {
                x = a[u];
            }
            else if (a[u] != x)
            {
                cout << 0 << '\n';
                return;
            }
        }

        if (dfs(dcc[id][0], 0, id))
        {
            if (x == -1)
            {
                ans = ans * V % mod;
            }
        }
        else
        {
            if (x > 0)
            {
                cout << 0 << '\n';
                return;
            }
        }
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