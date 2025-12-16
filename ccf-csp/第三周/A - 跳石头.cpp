#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int L, n, m;
int a[N];
bool check(int x)
{
    int res = 0, start = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] - start < x)
            res++;
        else
            start = a[i];
    }

    if (res <= m)
        return 1;
    return 0;
}
int bsearch(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if (check(mid))
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}
int main()
{
    cin >> L >> n >> m;
    for (int i = 0; i <= n; i++)
        scanf("%d", &a[i]);
    a[n++] = L;
    int ans = bsearch(0, L);

    printf("%d\n", ans);

    return 0;
}