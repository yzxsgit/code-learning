#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e5 + 10;

vector<vector<PII>> g;
vector<int> dist;
vector<int> depth;
int fa[N][20];

void dfs(int u, int p)
{
    fa[u][0] = p;
    for (int i = 1; i < 20; i++)
    {
        fa[u][i] = fa[fa[u][i - 1]][i - 1];
    }

    for (auto &[v, w] : g[u])
    {
        if (v == p) continue;
        depth[v] = depth[u] + 1;
        dist[v] = dist[u] + w;
        dfs(v, u);
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    for (int i = 19; i >= 0; i--)
    {
        if (depth[a] - (1 << i) >= depth[b])
        {
            a = fa[a][i];
        }
    }

    if (a == b)
        return a;

    for (int i = 19; i >= 0; i--)
    {
        if (fa[a][i]!=fa[b][i])
        {
            a = fa[a][i];
            b = fa[b][i];
        }
    }
    
    return fa[a][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(fa, 0, sizeof fa);
    int n, q;
    cin >> n >> q;

    g.resize(n + 1);
    dist.resize(n + 1);
    depth.resize(n + 1);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    dist[1] = 0;
    depth[1] = 0;
    dfs(1, 1);

    while (q--)
    {
        int a, b;
        cin >> a >> b;
        int l = lca(a, b);
        cout << dist[a] + dist[b] - 2 * dist[l] << '\n';
    }

    return 0;
}