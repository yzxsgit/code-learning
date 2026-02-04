#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e5 + 10, M = 3e5 + 10, INF = 0x3f3f3f3f;

struct Edge
{
    int a, b, w;
    bool used;
    bool operator< (const Edge &t) const
    {
        return w < t.w;
    }
} edge[M];

int n, m;
int depth[N], d1[N][17], d2[N][17], fa[N][17];
int p[N];
vector<PII> g[N];

int find(int x)
{
    if (x != p[x])
        p[x] = find(p[x]);

    return p[x];
}

i64 kruskal()
{
    for (int i = 1; i <= n; i++)
        p[i] = i;
    sort(edge, edge + m);

    i64 res = 0;
    for (int i = 0; i < m; i++)
    {
        int a = find(edge[i].a), b = find(edge[i].b), w = edge[i].w;
        if (a != b)
        {
            p[a] = b;
            res += w;
            edge[i].used = true;
        }
    }

    return res;
}

void build()
{
    for (int i = 0; i < m; i++)
    {
        if(edge[i].used)
        {
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            g[a].push_back({b, w});
            g[b].push_back({a, w});
        }
    }
}

void bfs()
{
    memset(d1, -0x3f, sizeof d1);
    memset(d2, -0x3f, sizeof d2);
    memset(depth, 0x3f, sizeof depth);
    depth[0] = 0, depth[1] = 1;
    queue<int> q;
    q.push(1);

    while (q.size())
    {
        int t = q.front();
        q.pop();

        for (auto [ver, w] : g[t])
        {
            if(depth[ver] > depth[t] + 1)
            {
                depth[ver] = depth[t] + 1;
                q.push(ver);

                fa[ver][0] = t;
                d1[ver][0] = w, d2[ver][0] = -INF;
                for (int k = 1; k <= 16; k++)
                {
                    int anc = fa[ver][k - 1];
                    fa[ver][k] = fa[anc][k - 1];
                    int distance[4] = {
                        d1[ver][k - 1], d2[ver][k - 1], d1[anc][k - 1], d2[anc][k - 1]
                    };
                    for (int u = 0; u < 4; u++)
                    {
                        int d = distance[u];
                        if (d > d1[ver][k]) d2[ver][k] = d1[ver][k], d1[ver][k] = d;
                        else if (d != d1[ver][k] && d > d2[ver][k]) d2[ver][k] = d;
                    }
                }
            }
        }
    }
}


int lca(int a, int b, int w)
{
    vector<int> dist;

    if (depth[a] < depth[b]) swap(a, b);

    for (int k = 16; k >= 0; k--)
    {
        int anc = fa[a][k];
        if(depth[anc] >= depth[b])
        {
            dist.push_back(d1[a][k]);
            dist.push_back(d2[a][k]);
            a = anc;
        }
    }

    if (a != b)
    {
        for (int k = 16; k >= 0; k--)
            if(fa[a][k] != fa[b][k])
            {
                dist.push_back(d1[a][k]);
                dist.push_back(d2[a][k]);
                dist.push_back(d1[b][k]);
                dist.push_back(d2[b][k]);
                a = fa[a][k];
                b = fa[b][k];
            }
            
        dist.push_back(d1[a][0]);
        dist.push_back(d1[b][0]);
    }

    int dist1 = -INF, dist2 = -INF;
    for (auto d : dist)
        if (d > dist1)
            dist2 = dist1, dist1 = d;
        else if (d != dist1 && d > dist2)
            dist2 = d;

    if (w > dist1)
        return w - dist1;
    else if (w > dist2)
        return w - dist2;
    else
        return INF;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
    }

    i64 sum = kruskal();
    build();
    bfs();

    i64 res = 1e18;
    for (int i = 0; i < m; i++)
    {
        if(!edge[i].used)
        {
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            res = min(res, sum + lca(a, b, w));
        }
    }

    cout << res << '\n';

    return 0;
}