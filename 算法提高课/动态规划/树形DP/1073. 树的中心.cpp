#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e4 + 10, M = 2 * N, INF = 0x3f3f3f3f;
int h[N], w[M], e[M], ne[M], idx;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int d1[N], d2[N], p1[N], u1[N];
int n;
bool is_leaf[N];

int dfs_d(int u,int father)
{
    d1[u] = d2[u] = -INF;

    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == father) continue;

        int d = dfs_d(j, u) + w[i];
        if (d >= d1[u])
            d2[u] = d1[u], d1[u] = d, p1[u] = j;
        else
            d2[u] = max(d2[u], d);
    }

    if(d1[u] == -INF)
    {
        d1[u] = d2[u] = 0;
        is_leaf[u] = true;
    }

    return d1[u];
}

void dfs_u(int u,int father)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == father) continue;
        if(p1[u] == j)
            u1[j] = max(u1[u], d2[u]) + w[i];
        else
            u1[j] = max(u1[u], d1[u]) + w[i];

        dfs_u(j, u);
    }
}

int main()
{
    memset(h, -1, sizeof h);
    
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dfs_d(1, -1);
    dfs_u(1, -1);

    int res = d1[1];
    for (int i = 2; i <= n; i++)
        if(is_leaf[i])
            res = min(res, u1[i]);
        else
            res = min(res, max(u1[i], d1[i]));

    cout << res << "\n";

    return 0;
}