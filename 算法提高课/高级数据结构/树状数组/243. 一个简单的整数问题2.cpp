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

i64 tr1[N], tr2[N];
int n, m;

int lowbit(i64 x)
{
    return x & -x;
}

void add(i64 tr[], int x, i64 c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

i64 sum(i64 tr[], int x)
{
    i64 res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

i64 prefix_sum(int x)
{
    return sum(tr1, x) * (x + 1) - sum(tr2, x);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
    {
        int b = a[i] - a[i - 1];
        add(tr1, i, b);
        add(tr2, i, (i64)i * b);
    }

    while (m--)
    {
        char op[2];
        cin >> op;
        if (*op == 'Q')
        {
            int l, r;
            cin >> l >> r;
            cout << prefix_sum(r) - prefix_sum(l - 1) << '\n';
        }
        else 
        {
            int l, r, d;
            cin >> l >> r >> d;
            add(tr1, l, d);
            add(tr1, r + 1, -d);
            add(tr2, l, d * l);
            add(tr2, r + 1, (r + 1) * -d);
        }
    }

    return 0;
}