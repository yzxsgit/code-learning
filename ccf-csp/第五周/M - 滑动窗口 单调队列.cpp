#include <iostream>

using namespace std;

const int N = 1e6 + 10;

int a[N], q[N], hh, tt = -1, n, k;

int main()
{
    scanf("%d%d", &n, &k);

    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && q[hh] < i - k + 1)
            hh++;
        while (hh <= tt && a[i] <= a[q[tt]])
            tt--;
        q[++tt] = i;

        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }

    puts("");

    hh = 0, tt = -1;

    for (int i = 0; i < n; i++)
    {
        if (hh <= tt && q[hh] < i - k + 1)
            hh++;
        while (hh <= tt && a[i] >= a[q[tt]])
            tt--;
        q[++tt] = i;

        if (i >= k - 1)
            printf("%d ", a[q[hh]]);
    }
    
    return 0;
}