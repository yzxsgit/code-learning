#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <functional>
#include <array>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

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

    const i64 INF = (i64)4e18;

    vector<i64> dist(n + 1);
    vector<int> cur(n + 1);
    vector<bool> vis(n + 1), inq(n + 1);

    auto spfa = [&]() -> bool
    {
        fill(dist.begin(), dist.end(), INF);
        fill(inq.begin(), inq.end(), false);
        queue<int> q;

        dist[s] = 0;
        inq[s] = true;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();
            inq[u] = false;

            for (auto [v, rev, cap, cost] : adj[u])
            {
                if (cap == 0)
                    continue;

                if (dist[v] > dist[u] + cost)
                {
                    dist[v] = dist[u] + cost;
                    if (!inq[v])
                    {
                        inq[v] = true;
                        q.push(v);
                    }
                }
            }
        }

        return dist[t] != INF;
    };

    function<i64(int, i64)> dfs = [&](int u, i64 flow) -> i64
    {
        if (u == t)
            return flow;

        vis[u] = true;

        for (int &i = cur[u]; i < (int)adj[u].size(); i++)
        {
            auto &[v, rev, cap, cost] = adj[u][i];

            if (vis[v] || cap == 0 || dist[v] != dist[u] + cost)
                continue;

            i64 d = dfs(v, min(flow, cap));
            if (d == 0)
                continue;

            cap -= d;
            adj[v][rev].cap += d;
            vis[u] = false;
            return d;
        }

        vis[u] = false;
        return 0;
    };

    auto DinicMCMF = [&]() -> pair<i64, i64>
    {
        i64 maxflow = 0, mincost = 0;

        while (spfa())
        {
            fill(cur.begin(), cur.end(), 0);

            while (true)
            {
                fill(vis.begin(), vis.end(), false);
                i64 flow = dfs(s, INF);
                if (flow == 0)
                    break;

                maxflow += flow;
                mincost += flow * dist[t];
            }
        }

        return {maxflow, mincost};
    };

    auto [maxflow, mincost] = DinicMCMF();
    cout << maxflow << ' ' << mincost << '\n';
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
