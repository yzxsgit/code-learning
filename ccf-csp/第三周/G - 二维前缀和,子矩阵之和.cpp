#include <bits/stdc++.h>
using namespace std;
const int N = 5e3 + 10;
long long a[N][N];
int n, m, q;
int main()
{
    scanf("%d%d%d", &n, &m, &q);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%lld", &a[i][j]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1];
    
    while (q--)
    {
        int x1, x2, y1, y2;
        scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
        printf("%lld\n", a[x2][y2] - a[x2][y1 - 1] - a[x1 - 1][y2] + a[x1 - 1][y1 - 1]);
    }

    return 0;
}