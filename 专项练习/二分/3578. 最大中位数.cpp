#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;
int a[N], n, m, k;
long long res;

bool check(long long x)
{
    long long t = 0;
    for (int i = m; i < n; i++)
        t += (x - a[i] > 0) ? x - a[i] : 0;
    return k >= t;
}
int bsearch(long long l,long long r)
{
    while (l < r)
    {
        long long mid = l + r >> 1;
        if(check(mid))
            l = mid + 1;
        else
            r = mid;
    }

    return l - 1;
}

int main()
{
    scanf("%d%d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n);

    m = n / 2;

    int ans = bsearch(a[m], k + a[n - 1] + 1);

    printf("%d\n", ans);

    return 0;
}