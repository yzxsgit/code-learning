#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;
const int N = 4e4 + 10;

vector<vector<int>> g(N);

int root, n;
int fa[N][16], depth[N];

void bfs(int u)
{
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[u] = 1;
    queue<int> q;
    q.push(u);

    while (q.size())
    {
        int t = q.front();
        q.pop();

        for (int j : g[t])
        {
            if(depth[j] > depth[t] + 1)
            {
                depth[j] = depth[t] + 1;
                q.push(j);
                fa[j][0] = t;
                for (int k = 1; k <= 15; k++)
                {
                    fa[j][k] = fa[fa[j][k - 1]][k - 1];
                }
            }
        }
    }
}

int lca(int a, int b)
{
    if (depth[a] < depth[b])
        swap(a, b);

    for (int i = 15; i >= 0; i--)
        if (depth[a] - depth[b] & (1 << i))
            a = fa[a][i];
    
    if(a == b)
        return a;

    for (int i = 15; i >= 0; i--)
        if(fa[a][i] != fa[b][i])
        {
            a = fa[a][i];
            b = fa[b][i];
        }

    return fa[a][0];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        if (!(~b))
            root = a;
        else
        {
            g[a].push_back(b);
            g[b].push_back(a);
        }
    }

    bfs(root);

    int m;
    cin >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        int p = lca(a, b);
        int res;
        if(p == a)
            res = 1;
        else if(p == b)
            res = 2;
        else
            res = 0;
        cout << res << '\n';
    }
    
    return 0;
}