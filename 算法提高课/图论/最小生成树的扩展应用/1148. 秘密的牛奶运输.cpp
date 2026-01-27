#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

const int N = 510, M = 1e4 + 10;

struct Edge
{
    int a, b, w;
    bool in_tree;
    bool operator< (const Edge &t) const
    {
        return w < t.w;
    }
} edge[M];

int h[M], e[M * 2], ne[M * 2], w[M * 2], idx;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dist1[N][N], dist2[N][N];
int n, m;

int p[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void dfs(int u, int fa, int maxd1, int maxd2, int d1[], int d2[])
{
    d1[u] = maxd1, d2[u] = maxd2;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (j != fa)
        {
            int td1 = maxd1, td2 = maxd2;
            if (w[i] > td1)
                td2 = td1, td1 = w[i];
            else if (w[i] < td1 && w[i] > td2)
                td2 = w[i];
            dfs(j, u, td1, td2, d1, d2);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    memset(h, -1, sizeof h);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        p[i] = i;

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        edge[i] = {a, b, c};
    }

    sort(edge, edge + m);

    long long sum = 0;
    for (int i = 0; i < m; i++)
    {
        int a = edge[i].a, b = edge[i].b, c = edge[i].w;
        int pa = find(a), pb = find(b);
        if (pa != pb)
        {
            sum += c;
            p[pa] = pb;
            add(a, b, c);
            add(b, a, c);
            edge[i].in_tree = true;
        }
    }

    for (int i = 1; i <= n; i++)
        dfs(i, -1, -1e9, -1e9, dist1[i], dist2[i]);

    long long res = 1e18;
    for (int i = 0; i < m; i++)
    {
        if(!edge[i].in_tree)
        {
            int a = edge[i].a, b = edge[i].b, w = edge[i].w;
            long long t;
            if (w > dist1[a][b])
                t = sum + w - dist1[a][b];
            else if(w>dist2[a][b])
                t = sum + w - dist2[a][b];
            res = min(res, t);
        }
    }

    cout << res << "\n";

    return 0;
}