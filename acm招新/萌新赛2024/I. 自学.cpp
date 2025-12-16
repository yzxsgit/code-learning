#include <iostream>

using namespace std;
const int N = 1e6 + 10;
int n;
long long a[N];

int bsearch(int k,long long m)
{
    int l = k, r = n;
    while (l < r)
    {
        int mid = l + r + 1 >> 1;
        if(a[mid] - a[k - 1] > m)
            r = mid - 1;
        else
            l = mid;
    }

    return l;
}

int main()
{
    int q;
    scanf("%d %d", &n, &q);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];

    while (q--)
    {
        int k;
        long long m;
        scanf("%d%lld", &k, &m);

        int res = bsearch(k, m);
        if(a[res] - a[k - 1] > m)
            res--;
        printf("%d\n", res - k + 1);
    }

    return 0;
}