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

const int N = 5e5 + 10;

int depth[N], fa[N][20];
vector<int> g[N];

void bfs(int root)
{
    memset(depth, 0x3f, sizeof depth);

    depth[0] = 0, depth[root] = 1;

    queue<int> q;
    q.push(root);

    while (!q.empty())
    {
        int u = q.front();
        q.pop();

        for (int v : g[u])
        {
            if (depth[v] > depth[u] + 1)
            {
                depth[v] = depth[u] + 1;
                q.push(v);
                fa[v][0] = u;
                for (int k = 1; k < 20; k++)
                    fa[v][k] = fa[fa[v][k - 1]][k - 1];
            }
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    for (int k = 19; k >= 0; k--)
        if (depth[fa[a][k]] >= depth[b])
            a = fa[a][k];
    
    if (a == b)
        return a;

    for (int k = 19; k >= 0; k--)
        if (fa[a][k] != fa[b][k])
            a = fa[a][k], b = fa[b][k];
    return fa[a][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, root;
    cin >> n >> m >> root;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs(root);

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        cout << lca(a, b) << '\n';
    }

    return 0;
}