#include <bits/stdc++.h>
using namespace std;

const int N = 2e4 + 10;
int n, m, p, q;
int x, y;

int find(int *f, int x)
{
    if (f[x] != x)
        f[x] = find(f, f[x]);

    return f[x];
}

int main()
{
    int a[N], b[N];
    scanf("%d%d%d%d", &n, &m, &p, &q);

    for (int i = 1; i <= n; i++)
        a[i] = i;
    for (int i = 1; i <= m; i++)
        b[i] = i;

    while (p--)
    {
        scanf("%d%d", &x, &y);
        x = find(a, x);
        y = find(a, y);
        a[x] = y;
    }

    while (q--)
    {
        scanf("%d%d", &x, &y);
        x = find(b, -x);
        y = find(b, -y);
        b[x] = y;
    }

    x = find(a, 1);
    y = find(b, 1);

    int res1 = 0, res2 = 0;
    for (int i = 1; i <= n; i++)
        if (x == find(a, i))
            res1++;

    for (int i = 1; i <= m; i++)
        if (y == find(b, i))
            res2++;

    printf("%d\n", min(res1, res2));

    return 0;
}