#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>
#include <array>
#include <functional>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

struct Edge
{
    int v, cap, rev; // 终点，剩余容量，反向边下标
};

void solve()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<Edge>> adj(n + 1);

    auto addEdge = [&](int u, int v, int cap) -> void
    {
        Edge a = {v, cap, (int)adj[v].size()};
        Edge b = {u, 0, (int)adj[u].size()};
        adj[u].push_back(a);
        adj[v].push_back(b);
    };

    for (int i = 0; i < m; i++)
    {
        int u, v, cap;
        cin >> u >> v >> cap;
        addEdge(u, v, cap);
    }

    struct Pre
    {
        int u, idx; // 前驱点，前驱边下标
    };

    vector<int> flow(n + 1);
    vector<Pre> pre(n + 1);

    auto bfs = [&]() -> bool
    {
        vector<bool> vis(n + 1, false);
        queue<int> q;

        q.push(s);
        vis[s] = true;
        flow[s] = 0x3f3f3f3f; // 源点初始流量设为无穷大

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (int i = 0; i < (int)adj[u].size(); i++)
            {
                auto [v, cap, rev] = adj[u][i];
                if (vis[v] || cap == 0)
                    continue;

                vis[v] = true;
                flow[v] = min(flow[u], cap); // 更新到 v 的瓶颈流量
                pre[v] = {u, i};
                q.push(v);

                if (v == t)
                    return true; // 找到一条增广路
            }
        }

        return false;
    };

    auto EK = [&]() -> int
    {
        int maxflow = 0;

        while (bfs())
        {
            int aug = flow[t]; // 本次增广量
            maxflow += aug;

            int cur = t;
            while (cur != s)
            {
                auto [u, idx] = pre[cur];
                adj[u][idx].cap -= aug;               // 正向边减流量
                adj[cur][adj[u][idx].rev].cap += aug; // 反向边加流量
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