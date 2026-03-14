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

int n, m, r, mod;
int w[N];
int wt[N];

int h[N], ne[N * 2], e[N * 2], idx;

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int son[N], id[N], fa[N], dep[N], siz[N], top[N];
int tot;

struct Node
{
    int l, r;
    i64 sum, lazy;
} tr[N * 4];

void dfs(int u, int f, int d)
{
    dep[u] = d;
    fa[u] = f;
    siz[u] = 1;
    int maxson = -1;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int v = e[i];
        if (v == f) continue;
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
        if (v == fa[u] || v == son[u]) continue;
        dfs(v, v);
    }
}

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void build(int u, int l, int r)
{
    tr[u].l = l, tr[u].r = r;
    if (l == r)
    {
        tr[u].sum = wt[l] % mod;
        return;
    }
    int mid = l + r >> 1;
    build(u << 1, l, mid);
    build(u << 1 | 1, mid + 1, r);
    pushup(u);
}

void pushdown(int u)
{
    if (tr[u].lazy) 
    {
        i64 lz = tr[u].lazy;

        tr[u << 1].lazy += lz;
        tr[u << 1 | 1].lazy += lz;
        tr[u << 1].sum += (i64)(tr[u << 1].r - tr[u << 1].l + 1) * lz;
        tr[u << 1 | 1].sum += (i64)(tr[u << 1 | 1].r - tr[u << 1 | 1].l + 1) * lz;
        tr[u].lazy = 0;
    }
}

void modify(int u, int l, int r, i64 val)
{
    if (l <= tr[u].l && r >= tr[u].r)
    {
        tr[u].sum += (i64)(tr[u].r - tr[u].l + 1) * val;
        tr[u].lazy += val;
        return;
    }

    pushdown(u);

    int mid = tr[u].l + tr[u].r >> 1;

    if (l <= mid) modify(u << 1, l, r, val);
    if (r > mid) modify(u << 1 | 1, l, r, val);

    pushup(u);
}

i64 query(int u, int l, int r)
{
    if (l <= tr[u].l && r >= tr[u].r)
    {
        return tr[u].sum % mod;
    }
    pushdown(u);
    int mid = tr[u].l + tr[u].r >> 1;

    i64 res = 0;
    if (l <= mid)
        res += query(u << 1, l, r);
    if (r > mid)
        res += query(u << 1 | 1, l, r);
    return res % mod;
}

void path_modify(int x, int y, i64 val)
{
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        modify(1, id[top[x]], id[x], val);
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    modify(1, id[x], id[y], val);
}

i64 path_query(int x, int y)
{
    i64 res = 0;
    while (top[x] != top[y])
    {
        if (dep[top[x]] < dep[top[y]])
            swap(x, y);
        res = (res + query(1, id[top[x]], id[x])) % mod;
        x = fa[top[x]];
    }
    if (dep[x] > dep[y])
        swap(x, y);
    res = (res + query(1, id[x], id[y])) % mod;
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    memset(h, -1, sizeof h);
    cin >> n >> m >> r >> mod;

    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
    }

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    dfs(r, 0, 1);

    dfs(r, r);

    build(1, 1, n);

    while (m--)
    {
        int op;
        cin >> op;
        if (op == 1)
        {
            int x, y, z;
            cin >> x >> y >> z;
            path_modify(x, y, z);
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
            modify(1, id[x], id[x] + siz[x] - 1, z);
        }
        else
        {
            int x;
            cin >> x;
            cout << query(1, id[x], id[x] + siz[x] - 1) << '\n';
        }
    }

    return 0;
}