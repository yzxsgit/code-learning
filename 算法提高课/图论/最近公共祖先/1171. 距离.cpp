#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e4 + 10, M = 2e4 + 10;

vector<PII> g[N], query[M];
int n, m;
int dist[N], p[N], st[N], res[M];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);

    return p[x];
}

void dfs(int u, int fa)
{
    for (auto [ver, w] : g[u])
    {
        if (ver == fa)
            continue;
        dist[ver] = dist[u] + w;
        dfs(ver, u);
    }
}

void tarjan(int u, int fa)
{
    st[u] = 1;

    for (auto [ver, w] : g[u])
    {
        if (ver == fa) continue; 
        if (!st[ver])
        {
            tarjan(ver, u);
            p[ver] = u;
        }
    }

    for (auto [q, id] : query[u])
    {
        if(st[q] == 2)
        {
            int anc = find(q);
            res[id] = dist[u] + dist[q] - 2 * dist[anc];
        }
    }

    st[u] = 2;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        g[a].push_back({b, c});
        g[b].push_back({a, c});
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        if (a != b)
        {
            query[a].push_back({b, i});
            query[b].push_back({a, i});
        }
        else
            res[i] = 0;
    }

    for (int i = 1; i <= n; i++)
        p[i] = i;

    dfs(1, -1);

    tarjan(1, -1);

    for (int i = 0; i < m; i++)
        cout << res[i] << '\n';

    return 0;
}