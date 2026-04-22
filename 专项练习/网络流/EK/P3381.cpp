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

const i64 inf = (i64)4e18;

struct Edge
{
    int v, rev;
    i64 cap, cost;
};

void solve()
{
    int n, m, s, t;

    cin >> n >> m >> s >> t;

    vector<vector<Edge>> adj(n + 1);

    auto add = [&](int u, int v, i64 cap, i64 cost) -> void
    {
        Edge a = {v, (int)adj[v].size(), cap, cost};
        Edge b = {u, (int)adj[u].size(), 0, -cost};
        adj[u].push_back(a);
        adj[v].push_back(b);
    };

    for (int i = 0; i < m; i++)
    {
        int u, v;
        i64 cap, cost;
        cin >> u >> v >> cap >> cost;
        add(u, v, cap, cost);
    }

    struct Pre
    {
        int u, idx;
    };

    vector<i64> flow(n + 1), dist(n + 1);
    vector<Pre> pre(n + 1);

    auto spfa = [&]() -> bool
    {
        fill(dist.begin(), dist.end(), inf);
        vector<bool> vis(n + 1, false);
        queue<int> q;

        dist[s] = 0;
        flow[s] = inf;
        q.push(s);
        vis[s] = true;

        while (q.size())
        {
            int u = q.front();
            q.pop();
            vis[u] = false;

            for (int i = 0; i < (int)adj[u].size(); i++)
            {
                auto [v, rev, cap, cost] = adj[u][i];
                if (cap == 0)
                    continue;

                if (dist[v] > dist[u] + cost)
                {
                    dist[v] = dist[u] + cost;
                    flow[v] = min(flow[u], cap);
                    pre[v] = {u, i};

                    if (!vis[v])
                    {
                        vis[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        return dist[t] != inf;
    };

    auto MCMF = [&]() -> pair<i64, i64>
    {
        i64 maxflow = 0, mincost = 0;

        while (spfa())
        {
            maxflow += flow[t];
            mincost += flow[t] * dist[t];

            int cur = t;
            while (cur != s)
            {
                auto [u, idx] = pre[cur];
                adj[u][idx].cap -= flow[t];
                adj[cur][adj[u][idx].rev].cap += flow[t];
                cur = u;
            }
        }

        return {maxflow, mincost};
    };

    auto [res1, res2] = MCMF();
    cout << res1 << ' ' << res2 << '\n';
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