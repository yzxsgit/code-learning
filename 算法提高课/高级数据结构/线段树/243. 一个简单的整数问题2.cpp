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

int n, m;
int w[N];
struct Node
{
    int l, r;
    i64 sum, add;
} tr[N * 4];

void pushup(int u)
{
    tr[u].sum = tr[u << 1].sum + tr[u << 1 | 1].sum;
}

void pushdown(int u)
{
    auto &root = tr[u], &left = tr[u << 1], &right = tr[u << 1 | 1];
    if (root.add)
    {
        left.add += root.add, left.sum += (i64)(left.r - left.l + 1) * root.add;
        right.add += root.add, right.sum += (i64)(right.r - right.l + 1) * root.add;
        root.add = 0;
    }
}

void build(int u, int l, int r)
{
    if (l == r)
    {
        tr[u] = {l, r, w[r], 0};
    }
    else 
    {
        tr[u] = {l, r};
        int mid = l + r >> 1;
        build(u << 1, l, mid);
        build(u << 1 | 1, mid + 1, r);
        pushup(u);
    }
}

void modify(int u, int l, int r, int d)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        tr[u].sum += (i64)(tr[u].r - tr[u].l + 1) * d;
        tr[u].add += d;
    }
    else 
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        if (l <= mid)
            modify(u << 1, l, r, d);
        if (r > mid)
            modify(u << 1 | 1, l, r, d);
        pushup(u);
    }
}

i64 query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r)
    {
        return tr[u].sum;
    }
    else 
    {
        pushdown(u);
        int mid = tr[u].l + tr[u].r >> 1;
        i64 res = 0;
        if (l <= mid)
            res = query(u << 1, l, r);
        if (r > mid)
            res += query(u << 1 | 1, l, r);
        return res;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];

    build(1, 1, n);
    while (m--)
    {
        char op[2];
        int l, r, d;
        cin >> op;
        if (*op == 'Q')
        {
            cin >> l >> r;
            cout << query(1, l, r) << '\n';
        }
        else 
        {
            cin >> l >> r >> d;
            modify(1, l, r, d);
        }
    }

    return 0;
}