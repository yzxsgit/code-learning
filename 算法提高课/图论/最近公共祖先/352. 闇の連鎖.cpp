#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e5 + 10, M = 2e5 + 10;

vector<int> g[N];
int n,m;
int d[N], depth[N], fa[N][17];

void bfs()
{
    memset(depth, 0x3f, sizeof depth);
    queue<int> q;
    q.push(1);
    depth[0] = 0, depth[1] = 1;

    while (q.size())
    {
        int t = q.front();
        q.pop();

        for (auto j : g[t])
        {
            if(depth[j] > depth[t] + 1)
            {
                depth[j] = depth[t] + 1;
                q.push(j);
                fa[j][0] = t;
                for (int k = 1; k <= 16; k++)
                {
                    int anc = fa[j][k - 1];
                    fa[j][k] = fa[anc][k - 1];
                }
            }
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    for (int k = 16; k >= 0; k--)
    {
        int anc = fa[a][k];
        if (depth[anc] >= depth[b])
            a = anc;
    }

    if (a == b)
        return a;

    for (int k = 16; k >= 0; k--)
        if(fa[a][k] != fa[b][k])
        {
            a = fa[a][k];
            b = fa[b][k];
        }

    return fa[a][0];
}

int ans = 0;
int dfs(int u, int father)
{
    int res = d[u];
    for (auto j : g[u])
    {
        if (j != father)
        {
            int s = dfs(j, u);
            if(s == 0)
                ans += m;
            else if(s == 1)
                ans++;
            res += s;
        }
    }

    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    bfs();

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        d[a]++, d[b]++, d[p] -= 2;
    }

    dfs(1, -1);

    cout << ans << '\n';

    return 0;
}