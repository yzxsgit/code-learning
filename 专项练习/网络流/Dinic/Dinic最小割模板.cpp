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
    i64 cap;  // 残量容量，注意这里是变换后的容量
    i64 real; // 原始容量
    bool ori; // 是否是原图边
};

void solve()
{
    int n, m, s, t;
    cin >> n >> m >> s >> t;

    i64 base = m + 1;

    vector<vector<Edge>> adj(n + 1);

    auto add = [&](int u, int v, i64 cap) -> void
    {
        // 为了在最小割容量最小的前提下，边数也最少
        i64 w = cap * base + 1;

        Edge a = {v, (int)adj[v].size(), w, cap, true};
        Edge b = {u, (int)adj[u].size(), 0, 0, false};

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

            for (auto [v, rev, cap, real, ori] : adj[u])
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
            auto &[v, rev, cap, real, ori] = adj[u][i];

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

    i64 res = Dinic();

    // 最小割容量
    i64 mincut = res / base;

    // 在最小割容量最小的前提下，割边数量最少
    i64 min_edges = res % base;

    // 在残量网络中，从 s 能到达的点属于 S 集合
    vector<bool> vis(n + 1, false);

    auto findS = [&]() -> void
    {
        queue<int> q;
        q.push(s);
        vis[s] = true;

        while (!q.empty())
        {
            int u = q.front();
            q.pop();

            for (auto [v, rev, cap, real, ori] : adj[u])
            {
                if (vis[v] || cap == 0)
                    continue;

                vis[v] = true;
                q.push(v);
            }
        }
    };

    findS();

    vector<int> S, T;
    for (int i = 1; i <= n; i++)
    {
        if (vis[i])
            S.push_back(i);
        else
            T.push_back(i);
    }

    // 原图中 S -> T 的边，就是最小割边
    vector<array<i64, 3>> cut;

    for (int u = 1; u <= n; u++)
    {
        if (!vis[u])
            continue;

        for (auto [v, rev, cap, real, ori] : adj[u])
        {
            if (ori && !vis[v])
            {
                cut.push_back({u, v, real});
            }
        }
    }

    cout << "mincut = " << mincut << '\n';
    cout << "min_edges = " << min_edges << '\n';

    cout << "S:";
    for (auto x : S)
        cout << ' ' << x;
    cout << '\n';

    cout << "T:";
    for (auto x : T)
        cout << ' ' << x;
    cout << '\n';

    cout << "cut_edges:\n";
    for (auto [u, v, w] : cut)
    {
        cout << u << ' ' << v << ' ' << w << '\n';
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