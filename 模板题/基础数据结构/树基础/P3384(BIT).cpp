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

const int N = 1e5 + 10, M = N * 2;

int h[N], e[M], ne[M], idx;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int n, m, r, mod;
int son[N], id[N], top[N], fa[N], dep[N], siz[N], tot;
int w[N], wt[N];

void dfs(int u, int f, int d)
{
    dep[u] = d;
    fa[u] = f;
    siz[u] = 1;
    int maxson = -1;

    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v == f)
            continue;
        dfs(v, u, d + 1);
        siz[u] += siz[v];
        if (siz[v] > maxson)
        {
            son[u] = v;
            maxson = siz[v];
        }
    }
}

void dfs(int u, int topf)
{
    id[u] = ++tot;
    wt[tot] = w[u];
    top[u] = topf;
    if (!son[u])
        return;
    dfs(son[u], topf);

    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v == fa[u] || v == son[u])
            continue;
        dfs(v, v);
    }
}

i64 c1[N], c2[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, i64 val)
{
    val %= mod;
    i64 val_i = ((i64)x * val) % mod;

    for (int i = x; i <= n; i += lowbit(i))
    {
        c1[i] = (c1[i] + val) % mod;
        c2[i] = (c2[i] + val_i) % mod;
    }
}

void range_add(int l, int r, i64 val)
{
    add(l, val);
    add(r + 1, mod - (val % mod));
}

i64 query(int x)
{
    i64 sum1 = 0, sum2 = 0;
    for (int i = x; i > 0; i -= lowbit(i))
    {
        sum1 = (sum1 + c1[i]) % mod;
        sum2 = (sum2 + c2[i]) % mod;
    }

    i64 res = ((x + 1) * sum1 % mod - sum2) % mod;

    return (res + mod) % mod;
}

i64 range_query(int l, int r)
{
    return (query(r) - query(l - 1) + mod) % mod;
}

void path_add(int x, int y, int val)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        range_add(id[top[x]], id[x], val);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    range_add(id[x], id[y], val);
}

i64 path_query(int x, int y)
{
    i64 res = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        res = (res + range_query(id[top[x]], id[x])) % mod;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    res = (res + range_query(id[x], id[y])) % mod;

    return (res + mod) % mod;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof h);
    cin >> n >> m >> r >> mod;

    for (int i = 1; i <= n; i++)
        cin >> w[i];

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(r, 0, 1);

    dfs(r, r);

    for (int i = 1; i <= n; i++)
    {
        range_add(i, i, wt[i]);
    }

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, z;
            cin >> x >> y >> z;
            path_add(x, y, z);
        }
        else if (op == 2)
        {
            int x, y;
            cin >> x >> y;
            cout << path_query(x, y) << '\n';
        }
        else if (op == 3)
        {
            int x, z;
            cin >> x >> z;
            range_add(id[x], id[x] + siz[x] - 1, z);
        }
        else
        {
            int x;
            cin >> x;
            cout << range_query(id[x], id[x] + siz[x] - 1) << '\n';
        }
    }

    return 0;
}