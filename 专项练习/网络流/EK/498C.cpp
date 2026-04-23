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

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    vector<map<int, int>> cnt(n + 1);
    vector<pair<int, int>> edges;
    vector<int> primes;

    for (int i = 1; i <= n; i++)
    {
        int x = a[i];

        for (int j = 2; j * j <= x; j++)
        {
            int c = 0;
            while (x % j == 0)
            {
                x /= j;
                c++;
            }
            if (c)
            {
                cnt[i][j] = c;
                primes.push_back(j);
            }
        }
        if (x > 1)
        {
            cnt[i][x] = 1;
            primes.push_back(x);
        }
    }

    sort(primes.begin(), primes.end());
    primes.erase(unique(primes.begin(), primes.end()), primes.end());

    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x % 2 == 0)
            swap(x, y);
        edges.push_back({x, y});
    }

    int res = 0;
    for (int p : primes)
    {

        struct Pre
        {
            int u, idx;
        };

        vector<vector<Edge>> adj(n + 2);
        vector<int> flow(n + 2);
        vector<Pre> pre(n + 2);

        int s = 0;

        int t = n + 1;

        auto add = [&](int u, int v, int cap) -> void
        {
            Edge a = {v, (int)adj[v].size(), cap};
            Edge b = {u, (int)adj[u].size(), 0};
            adj[u].push_back(a);
            adj[v].push_back(b);
        };

        for (int i = 1; i <= n; i += 2)
        {
            if (cnt[i].count(p) != 0)
            {
                add(s, i, cnt[i][p]);
            }
        }

        for (int i = 2; i <= n; i += 2)
        {
            if (cnt[i].count(p) != 0)
            {
                add(i, t, cnt[i][p]);
            }
        }

        for (int i = 0; i < m; i++)
        {
            auto [x, y] = edges[i];
            if (cnt[x].count(p) != 0 && cnt[y].count(p) != 0)
            {
                add(x, y, inf);
            }
        }

        auto bfs = [&]() -> bool
        {
            queue<int> q;
            vector<bool> vis(n + 2, false);

            q.push(s);
            vis[s] = true;
            flow[s] = inf;

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
                maxflow += flow[t];

                int cur = t;
                while (cur != s)
                {
                    auto [u, idx] = pre[cur];
                    adj[u][idx].cap -= flow[t];
                    adj[cur][adj[u][idx].rev].cap += flow[t];
                    cur = u;
                }
            }
            return maxflow;
        };

        res += EK();
    }

    cout << res << '\n';
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