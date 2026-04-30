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

const int inf = 1e9;

struct Edge
{
    int v, rev, cap;
};

vector<bool> is_primes;

void solve()
{
    int n;

    cin >> n;

    vector<int> a(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    int odd = 0, even = 0;

    for (int i = 1; i <= n; i++)
    {
        if (a[i] & 1)
            odd++;
        else
            even++;
    }

    if (odd != even)
    {
        cout << "Impossible\n";
        return;
    }

    int s = 0, t = n + 1;

    vector<vector<Edge>> adj(n + 2);

    auto add = [&](int u, int v, int cap) -> void
    {
        Edge a = {v, (int)adj[v].size(), cap};
        Edge b = {u, (int)adj[u].size(), 0};
        adj[u].push_back(a);
        adj[v].push_back(b);
    };

    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        if (x & 1)
        {
            add(i, t, 2);
        }
        else
        {
            add(s, i, 2);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] & 1)
            continue;
        for (int j = 1; j <= n; j++)
        {
            if (i == j || a[j] % 2 == 0)
                continue;
            if (!is_primes[a[i] + a[j]])
                continue;
            add(i, j, 1);
        }
    }

    vector<int> level(n + 2), cur(n + 2);

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

    function<int(int, int)> dfs = [&](int u, int flow) -> int
    {
        if (u == t)
            return flow;

        for (int &i = cur[u]; i < (int)adj[u].size(); i++)
        {
            auto &[v, rev, cap] = adj[u][i];

            if (cap == 0 || level[v] != level[u] + 1)
                continue;

            int d = dfs(v, min(cap, flow));

            if (d == 0)
                continue;

            cap -= d;
            adj[v][rev].cap += d;
            return d;
        }

        return 0;
    };

    auto Dinic = [&]() -> int
    {
        int maxflow = 0;

        while (bfs())
        {
            fill(cur.begin(), cur.end(), 0);

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

    if (Dinic() == n)
    {
        vector<vector<int>> g(n + 1);

        for (int i = 1; i <= n; i++)
        {
            if (a[i] % 2 == 1)
                continue;

            for (auto [v, rev, cap] : adj[i])
            {
                if (v < 1 || v > n)
                    continue;

                if (adj[v][rev].cap == 1)
                {
                    g[i].push_back(v);
                    g[v].push_back(i);
                }
            }
        }

        vector<bool> vis(n + 1, false);
        vector<vector<int>> ans;

        for (int i = 1; i <= n; i++)
        {
            if (vis[i])
                continue;

            vector<int> cur;
            int u = i, fa = 0;

            while (true)
            {
                cur.push_back(u);
                vis[u] = true;

                int nxt;
                if (g[u][0] != fa)
                    nxt = g[u][0];
                else
                    nxt = g[u][1];

                fa = u;
                u = nxt;

                if (u == i)
                    break;
            }

            ans.push_back(cur);
        }

        cout << ans.size() << '\n';

        for (auto &vec : ans)
        {
            cout << vec.size() << ' ';
            for (auto item : vec)
                cout << item << ' ';
            cout << '\n';
        }
    }
    else
    {
        cout << "Impossible\n";
    }
}

void init()
{
    int N = 2e4;

    is_primes.assign(N + 1, true);
    is_primes[0] = is_primes[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (!is_primes[i])
            continue;
        for (int j = i * i; j <= N; j += i)
            is_primes[j] = false;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    init();

    int T;
    T = 1;
    while (T--)
    {
        solve();
    }
    return 0;
}