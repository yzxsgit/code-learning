#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int n, k;
int h[N], w[N];
bool check(int x)
{
    int res = 0;
    for (int i = 0; i < n; i++)
        res += (w[i] / x) * (h[i] / x);

    if (res < k)
        return 1;
    else
        return 0;
}
int bsearch(int l, int r)
{
    while (l < r)
    {
        int mid = l + r + 1>> 1;
        if (check(mid))
            r = mid - 1;
        else
            l = mid;
    }

    return l;
}
int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d%d", &h[i], &w[i]);

    printf("%d", bsearch(1, 1e5));

    return 0;
}