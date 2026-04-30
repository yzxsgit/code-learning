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
#include <iomanip>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

const int inf = 1e9;

struct Edge
{
    int v, rev;
    i64 cap;
};

void solve()
{
    int n, m, x;
    cin >> n >> m >> x;

    vector<Edge> edges(m);

    for (int i = 0; i < m; i++)
    {
        int u, v, cap;
        cin >> u >> v >> cap;

        edges[i] = {u, v, cap};
    }

    auto check = [&](double res) -> bool
    {
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
            auto [u, v, cap] = edges[i];
            i64 w = min((i64)x, (i64)(cap / res));
            if (w > 0)
                add(u, v, w);
        }

        int s = 1, t = n;
        vector<int> level(n + 1), cur(n + 1);

        auto bfs = [&]() -> bool
        {
            fill(level.begin(), level.end(), -1);
            queue<int> q;
            level[s] = 0;
            q.push(s);

            while (q.size())
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
                return flow;

            for (int &i = cur[u]; i < (int)adj[u].size(); i++)
            {
                auto &[v, rev, cap] = adj[u][i];

                if (cap == 0 || level[v] != level[u] + 1)
                    continue;

                i64 d = dfs(v, min(flow, cap));
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

        return Dinic() >= x;
    };

    double l = 0, r = 1e9;

    for (int i = 0; i < 80; i++)
    {
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }

    cout << fixed << setprecision(10) << l * x << '\n';
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