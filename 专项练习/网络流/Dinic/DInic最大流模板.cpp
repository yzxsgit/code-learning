#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <functional>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

const int inf = 1e9;

struct Edge
{
    int v, rev, cap; // 终点，反向边下标，剩余容量
};

void solve()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    vector<vector<Edge>> adj(n + 1);

    auto add = [&](int u, int v, int cap) -> void
    {
        Edge a = {v, (int)adj[v].size(), cap};
        Edge b = {u, (int)adj[u].size(), 0};
        adj[u].push_back(a);
        adj[v].push_back(b);
    };

    for (int i = 0; i < m; i++)
    {
        int u, v, cap;
        cin >> u >> v >> cap;
        add(u, v, cap);
    }

    vector<int> level(n + 1), cur(n + 1);

    auto bfs = [&]() -> bool
    {
        fill(level.begin(), level.end(), -1);
        queue<int> q;

        level[s] = 0;
        q.push(s);

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto [v, rev, cap] : adj[u])
            {
                if (cap == 0 || level[v] != -1)
                    continue;

                level[v] = level[u] + 1; // 建分层图
                q.push(v);
            }
        }

        return level[t] != -1; // 汇点还能到达
    };

    function<int(int, int)> dfs = [&](int u, int flow) -> int
    {
        if (u == t)
            return flow; // 到汇点，返回本次流量

        for (int &i = cur[u]; i < (int)adj[u].size(); i++)
        {
            auto &[v, rev, cap] = adj[u][i];

            if (cap == 0 || level[v] != level[u] + 1)
                continue; // 只走分层图中的边

            int d = dfs(v, min(flow, cap));
            if (d == 0)
                continue;

            cap -= d;             // 正向边减
            adj[v][rev].cap += d; // 反向边加
            return d;
        }

        return 0; // 送不出流
    };

    auto Dinic = [&]() -> int
    {
        int maxflow = 0;

        while (bfs())
        {
            fill(cur.begin(), cur.end(), 0); // 当前弧初始化

            while (true)
            {
                int flow = dfs(s, inf);
                if (flow == 0)
                    break;
                maxflow += flow;
            }
        }

        return maxflow;
    };

    cout << Dinic() << '\n';
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