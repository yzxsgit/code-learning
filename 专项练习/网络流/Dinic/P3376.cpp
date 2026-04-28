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

const i64 inf = 4e18;

struct Edge
{
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
        Edge a = {v, (int)adj[v].size(), cap};
        Edge b = {u, (int)adj[u].size(), 0};
        adj[u].push_back(a);
        adj[v].push_back(b);
    };

    for (int i = 0; i < m; i++)
    {
        int u, v;
        i64 cap;
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

                level[v] = level[u] + 1;
                q.push(v);
            }
        }

        return level[t] != -1;
    };

    function<i64(int, i64)> dfs = [&](int u, i64 flow) -> i64
    {
        if (u == t)
        {
            return flow;
        }

        for (int &i = cur[u]; i < (int)adj[u].size(); i++)
        {
            auto &[v, rev, cap] = adj[u][i];
            if (cap == 0 || level[u] != level[v] - 1)
                continue;

            int d = dfs(v, min(flow, cap));
            if (d == 0)
                continue;

            cap -= d;
            adj[v][rev].cap += d;
            return d;
        }

        return 0;
    };

    auto Dinic = [&]() -> i64
    {
        i64 maxflow = 0;

        while (bfs())
        {
            fill(cur.begin(), cur.end(), 0);

            while (true)
            {
                i64 flow = dfs(s, inf);
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