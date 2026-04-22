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

const int inf = 0x3f3f3f3f;

struct Edge
{
    int v, rev, cap;
};

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    int s = 0, t = 2 * n + 1;
    vector<vector<Edge>> adj(2 * n + 2);

    auto add = [&](int u, int v, int cap) -> void
    {
        Edge x = {v, (int)adj[v].size(), cap};
        Edge y = {u, (int)adj[u].size(), 0};
        adj[u].push_back(x);
        adj[v].push_back(y);
    };

    for (int i = 1; i <= n; i++)
    {
        add(s, i, a[i]);     
        add(i + n, t, b[i]); 
        add(i, i + n, inf);   
    }

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        add(x, y + n, inf); 
        add(y, x + n, inf); 
    }

    struct Pre
    {
        int u, idx;
    };

    vector<int> flow(2 * n + 2);
    vector<Pre> pre(2 * n + 2);

    auto bfs = [&]() -> bool
    {
        queue<int> q;
        vector<bool> vis(2 * n + 2, false);
        q.push(s);
        vis[s] = true;
        flow[s] = inf;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int i = 0; i < (int)adj[u].size(); i++)
            {
                auto [v, rev, cap] = adj[u][i];
                if (vis[v] || cap == 0)
                    continue;

                vis[v] = true;
                flow[v] = min(flow[u], cap);
                pre[v] = {u, i};
                q.push(v);

                if (v == t)
                    return true;
            }
        }

        return false;
    };

    auto EK = [&]() -> int
    {
        int maxflow = 0;

        while (bfs())
        {
            maxflow += flow[t];

            int cur = t;

            while (cur != s)
            {
                auto [u, idx] = pre[cur];
                adj[u][idx].cap -= flow[t];
                adj[cur][adj[u][idx].rev].cap += flow[t];
                cur = u;
            }
        }

        return maxflow;
    };

    int sum_a = 0, sum_b = 0;
    for (int i = 1; i <= n; i++)
        sum_a += a[i], sum_b += b[i];
    
    if (sum_a != sum_b)
    {
        cout << "NO\n";
        return;
    }

    int ek = EK();

    if (sum_a == ek)
    {
        cout << "YES\n";

        vector<vector<int>> res(n + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
        {
            for (auto [v, rev, cap] : adj[i])
            {
                if (v >= n + 1 && v <= 2 * n)
                {
                    int j = v - n;
                    res[i][j] = adj[v][rev].cap;
                }
            }
        }

        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                cout << res[i][j] << (j == n ? '\n' : ' ');
    }
    else
    {
        cout << "NO\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}