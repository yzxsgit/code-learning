#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 2e5 + 10;
int a[N];
int t, n;
LL x;
bool check(int h)
{
    LL res = 0;
    for (int i = 0; i < n; i++)
        if (a[i] < h)
            res += h - a[i];

    return res <= x;
}
LL bsearch(LL l, LL r)
{
    LL mid;
    while (l <= r)
    {
        mid = l + r >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid - 1;
    }

    return r;
}
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d%lld", &n, &x);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);

        printf("%lld\n", bsearch(1, 2e9));
    }

    return 0;
}