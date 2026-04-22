#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

struct Edge{
    int v, rev;
    i64 cap;
};

void solve()
{
    int n, m, s, t;

    cin >> n >> m >> s >> t;

    vector<vector<Edge>> adj(n + 1);

    auto add = [&](int u, int v, i64 cap) -> void
    {
        Edge a = {v, adj[v].size(), cap};
        Edge b = {u, adj[u].size(), 0};
        adj[u].push_back(a);
        adj[v].push_back(b);
    };

    for (int i = 0; i < m; i++)
    {
        int u, v, cap;
        cin >> u >> v >> cap;
        add(u, v, cap);
    }

    struct Pre
    {
        int u, idx;
    };

    vector<i64> flow(n + 1);
    vector<Pre> pre(n + 1);

    auto bfs = [&]() -> bool
    {
        vector<bool> vis(n + 1, false);
        queue<int> q;

        q.push(s);
        vis[s] = true;
        flow[s] = 0x3f3f3f3f3f3f3f3f3f;

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

    auto EK = [&]() -> i64
    {
        i64 maxflow = 0;

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

    cout << EK() << '\n';
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