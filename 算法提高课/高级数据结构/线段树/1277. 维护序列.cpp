#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e5 + 10;

int n, m, p;
int w[N];
struct Node
{
    int l, r;
    int sum;
    int add, mul;
} tr[N * 4];

void pushup(int u)
{
    tr[u].sum = (tr[u << 1].sum + tr[u << 1 | 1].sum) % p;
}

void eval(Node &t, int add, int mul)
{
    t.sum = ((i64)t.sum * mul + (i64)(t.r - t.l + 1) * add) % p;
    t.mul = (i64)t.mul * mul % p;
    t.add = ((i64)t.add * mul + add) % p;
}

void pushdown(int u)
{
    eval(tr[u << 1], tr[u].add, tr[u].mul);
    eval(tr[u << 1 | 1], tr[u].add, tr[u].mul);
    tr[u].add = 0, tr[u].mul = 1;
}

void build(int u, int l, int r)
{
    if (l == r)
    {
        tr[u] = {l, r, w[r], 0, 1};
    }
    else 
    {
        tr[u] = {l, r, 0, 0, 1};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int add, int mul)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        eval(tr[u], add, mul);
    }
    else 
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, add, mul);
        if (r > mid)
            modify(u << 1 | 1, l, r, add, mul);
        pushup(u);
    }
}

int query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u].sum;
    else 
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        int res = 0;
        if (l <= mid)
            res = query(u << 1, l, r);
        if (r > mid)
            res = (res + query(u << 1 | 1, l, r)) % p;
        return res;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> p;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    build(1, 1, n);

    cin >> m;
    while (m--)
    {
        int t, l, r, c;
        cin >> t;
        if (t == 1)
        {
            cin >> l >> r >> c;
            modify(1, l, r, 0, c);
        }
        else if (t == 2)
        {
            cin >> l >> r >> c;
            modify(1, l, r, c, 1);
        }
        else 
        {
            cin >> l >> r;
            cout << query(1, l, r) << '\n';
        }
    }

    return 0;
}