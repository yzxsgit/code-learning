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
    i64 cap;
};

void solve()
{
    int n, m, g;

    cin >> n >> m >> g;

    vector<int> sex(n + 1);
    vector<int> cost(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> sex[i];

    for (int i = 1; i <= n; i++)
        cin >> cost[i];

    i64 ans = 0;

    int s = 0, t = n + m + 1;

    vector<vector<Edge>> adj(t + 1);

    auto add = [&](int u, int v, i64 cap) -> void
    {
        Edge a = {v, (int)adj[v].size(), cap};
        Edge b = {u, (int)adj[u].size(), 0};
        adj[u].push_back(a);
        adj[v].push_back(b);
    };

    for (int i = 1; i <= n; i++)
    {
        if (sex[i] == 0)
            add(s, i, cost[i]);
        else
            add(i, t, cost[i]);
    }

    for (int i = 1; i <= m; i++)
    {
        int id = i + n;

        bool need;
        int w, k;

        cin >> need >> w >> k;

        vector<int> dogs(k);
        for (int i = 0; i < k; i++)
            cin >> dogs[i];

        bool flag;

        cin >> flag;

        ans += w;

        i64 loss = w + flag * g;

        if (need == 1)
        {
            for (auto dog : dogs)
                add(dog, id, inf);

            add(id, t, loss);
        }
        else
        {
            add(s, id, loss);

            for (auto dog : dogs)
                add(id, dog, inf);
        }
    }

    vector<int> level(t + 1), cur(t + 1);

    auto bfs = [&]() -> bool
    {
        fill(level.begin(), level.end(), -1);
        queue<int> q;

        q.push(s);
        level[s] = 0;

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
        if (t == u)
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

    cout << ans - Dinic() << '\n';
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