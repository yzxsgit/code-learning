#include <bits/stdc++.h>
using namespace std;
const int N = 2e6 + 10;
int n, m;
long long a[N], b[N], c[N];
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%lld", &a[i]);

    for (int i = 1; i <= n; i++)
        b[i] = b[i - 1] + a[i];
    for (int i = 1; i <= n; i++)
        c[i] = c[i - 1] ^ a[i];
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        if (x == 1)
            printf("%lld\n", b[z] - b[y - 1]);
        else
            printf("%lld\n", c[z] ^ c[y - 1]);
    }

    return 0;
}