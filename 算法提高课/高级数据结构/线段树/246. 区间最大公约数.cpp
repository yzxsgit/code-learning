#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 5e5 + 10;

int n, m;
i64 w[N];

struct Node
{
    int l, r;
    i64 sum, d;
} tr[N * 4];

i64 gcd(i64 x, i64 y)
{
    return y ? gcd(y, x % y) : x;
}

void pushup(Node &u, Node &l, Node &r)
{
    u.sum = l.sum + r.sum;
    u.d = gcd(l.d, r.d);
}

void pushup(int u)
{
    pushup(tr[u], tr[u << 1], tr[u << 1 | 1]);
}

void build(int u, int l, int r)
{
    if (l == r)
    {
        i64 b = w[r] - w[r - 1];
        tr[u] = {l, r, b, b};
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

void modify(int u, int x, i64 v)
{
    if (tr[u].l == x && tr[u].r == x)
    {
        i64 b = tr[u].sum + v;
        tr[u] = {x, x, b, b};
    }
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

Node query(int u, int l, int r)
{
    if (tr[u].l >= l && tr[u].r <= r) return tr[u];
    else
    {
        int mid = tr[u].l + tr[u].r >> 1;
        if (r <= mid)
            return query(u << 1, l, r);
        else if (l > mid)
            return query(u << 1 | 1, l, r);
        else 
        {
            auto left = query(u << 1, l, r);
            auto right = query(u << 1 | 1, l, r);
            Node res;
            pushup(res, left, right);
            return res;
        }
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
        int l, r;
        i64 d;
        cin >> op;
        if (*op == 'C')
        {
            cin >> l >> r >> d;
            modify(1, l, d);
            if (r + 1 <= n)
                modify(1, r + 1, -d);
        }
        else 
        {
            cin >> l >> r;
            auto left = query(1, 1, l);
            Node right = {0, 0, 0, 0};
            if (l + 1 <= r)
                right = query(1, l + 1, r);
            cout << abs(gcd(left.sum, right.d)) << '\n';
        }
    }

    return 0;
}