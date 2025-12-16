#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N = 1e6 + 10;
LL a[N], b[N];
int n, m;
bool check(int h)
{
    LL res = 0;
    for (int i = 1; i <= n; i++)
        if(a[i] - h > 0)
            res += a[i] - h;
    if (res < m)
        return true;
    else
        return false;
}
int bsearch(int l,int r)
{
    while (l <= r)
    {
        int mid = l + r >> 1;
        if(check(mid))
            r = mid - 1;
        else
            l = mid + 1;
    }

    return r;
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);
    sort(a + 1, a + n + 1);

    for (int i = 1; i <= n; i++)
        b[i] = b[i-1] + a[i];

    int ans = bsearch(0, a[n]);

    printf("%d\n", ans);

    return 0;
}