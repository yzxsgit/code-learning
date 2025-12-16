#include <iostream>

using namespace std;
const int N = 5e4 + 10;

int q[N], f[N], a[N];
int n, t;

bool check(int m)
{
    int hh = 0, tt = 0;
    q[0] = f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (q[hh] < i - m - 1)
            hh++;
        f[i] = f[q[hh]] + a[i];
        while (hh <= tt && f[q[tt]] >= f[i])
            tt--;
        q[++tt] = i;
    }

    int res = 1e9;
    for (int i = n - m; i <= n; i++)
        res = min(res, f[i]);
    return res <= t;
}

int bsearch(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

int main()
{
    scanf("%d%d", &n, &t);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    int res = bsearch(0, n);

    printf("%d\n", res);

    return 0;
}