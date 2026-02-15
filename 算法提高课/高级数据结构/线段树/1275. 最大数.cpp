#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 2e5 + 10;

struct Node
{
    int l, r;
    int tmax;
} tr[N * 4];

int m, p;

void pushup(int u)
{
    tr[u].tmax = max(tr[u << 1].tmax, tr[u << 1 | 1].tmax);
}

void build(int u, int l, int r)
{
    tr[u] = {l, r};
    if (l == r) return;
    int mid = l + r >> 1;
    build(u << 1, l, mid), build(u << 1 | 1, mid + 1, r);
}

int query(int u, int l, int r)
{
    if (l <= tr[u].l && r >= tr[u].r) return tr[u].tmax;
    int mid = tr[u].l + tr[u].r >> 1;
    int v = 0;
    if (l <= mid)
        v = query(u << 1, l, r);
    if (r > mid)
        v = max(v, query(u << 1 | 1, l, r));
    return v;
}

void modify(int u, int x, int v)
{
    if (tr[u].l == x && tr[u].r == x)
        tr[u].tmax = v;
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (x <= mid)
            modify(u << 1, x, v);
        else
            modify(u << 1 | 1, x, v);
        pushup(u);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n = 0, last = 0;
    cin >> m >> p;

    build(1, 1, m);

    while (m--)
    {
        char op[2];
        int x;
        cin >> op >> x;
        if (*op == 'Q')
        {
            last = query(1, n - x + 1, n);
            cout << last << '\n';
        }
        else
        {
            x = ((i64) last + x) % p;
            modify(1, n + 1, x);
            n++;
        }
    }

    return 0;
}