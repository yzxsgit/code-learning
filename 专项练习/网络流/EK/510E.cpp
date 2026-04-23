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

struct edge
{
    int v, rev, cap;
};

vector<bool> is_prime;

void init()
{
    int N = 20000;
    is_prime.assign(N + 1, true);
    is_prime[0] = is_prime[1] = false;

    for (int i = 2; i * i <= N; i++)
    {
        if (!is_prime[i])
            continue;
        for (int j = i * i; j <= N; j += i)
        {
            is_prime[j] = false;
        }
    }
}

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

    struct Pre
    {
        int u, idx;
    };

    vector<int> flow(n + 2);
    vector<Pre> pre(n + 2);
    vector<vector<edge>> adj(n + 2);

    auto add = [&](int u, int v, int cap)
    {
        edge x = {v, (int)adj[v].size(), cap};
        edge y = {u, (int)adj[u].size(), 0};
        adj[u].push_back(x);
        adj[v].push_back(y);
    };

    for (int i = 1; i <= n; i++)
    {
        int x = a[i];
        if (x % 2 == 0)
        {
            add(s, i, 2);
        }
        else
        {
            add(i, t, 2);
        }
    }

    for (int i = 1; i <= n; i++)
    {
        if (a[i] % 2 == 1)
            continue;
        for (int j = 1; j <= n; j++)
        {
            if (i == j || a[j] % 2 == 0)
                continue;
            if (!is_prime[a[i] + a[j]])
                continue;
            add(i, j, 1);
        }
    }

    auto bfs = [&]() -> bool
    {
        queue<int> q;
        vector<bool> vis(n + 2, false);

        vis[s] = true;
        q.push(s);
        flow[s] = 1e9;

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
                if (t == v)
                    return true;
            }
        }

        return false;
    };

    auto EK = [&]() -> int
    {
        int maxflow = 0;

        while (bfs())
        {
            int aug = flow[t];
            maxflow += aug;

            int cur = t;

            while (cur != s)
            {
                auto [u, idx] = pre[cur];
                adj[u][idx].cap -= aug;
                adj[cur][adj[u][idx].rev].cap += aug;
                cur = u;
            }
        }

        return maxflow;
    };

    if (EK() == n)
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
            for (auto x : vec)
                cout << x << ' ';
            cout << '\n';
        }
    }
    else
    {
        cout << "Impossible\n";
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