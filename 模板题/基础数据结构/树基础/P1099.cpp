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
using PII = pair<int, int>;

vector<vector<PII>> g;
vector<int> dist, fa;
vector<int> path;

int max_dist = -1;
int father_node = 0;
int max_d;

void dfs_branch(int u, int p, int d, const vector<bool> &in_path)
{
    max_d = max(d, max_d);
    for (auto &edge : g[u])
    {
        int v = edge.first;
        int w = edge.second;
        if (v == p || in_path[v])
            continue;
        dfs_branch(v, u, d + w, in_path);
    }
}

void dfs(int u, int p, int d)
{
    dist[u] = d;
    fa[u] = p;

    if (d > max_dist)
    {
        max_dist = d;
        father_node = u;
    }

    for (auto &edge : g[u])
    {
        int v = edge.first;
        int w = edge.second;
        if (v == p)
            continue;
        dfs(v, u, w + d);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, s;
    cin >> n >> s;
    g.resize(n + 1);
    dist.resize(n + 1);
    fa.resize(n + 1);
    path.clear();

    for (int i = 0; i < n - 1; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
        g[b].push_back({a, w});
    }

    dfs(1, -1, 0);
    int S = father_node;

    max_dist = -1;
    dfs(S, -1, 0);
    int T = father_node;

    int curr = T;
    while (curr != -1)
    {
        path.push_back(curr);
        curr = fa[curr];
    }

    vector<bool> in_path(n + 1, false);
    for (int i : path)
        in_path[i] = true;

    max_d = 0;
    for (int u : path)
    {
        dfs_branch(u, -1, 0, in_path);
    }

    reverse(path.begin(), path.end());

    int ans = 2e9;

    for (int i = 0, j = 0; i < path.size(); i++)
    {
        while (j + 1 < path.size() && dist[path[j + 1]] - dist[path[i]] <= s)
            j++;

        int ecc = max({max_d, dist[path[i]], dist[T] - dist[path[j]]});

        ans = min(ecc, ans);
    }

    cout << ans << '\n';

    return 0;
}