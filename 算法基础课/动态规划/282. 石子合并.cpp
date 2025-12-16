#include <bits/stdc++.h>
using namespace std;
const int N = 310;
int a[N], s[N];
int f[N][N];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];

    for (int len = 2; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int l = i, r = i + len - 1;
            f[l][r] = 0x3f3f3f3f;
            for (int j = l; j < r; j++)
                f[l][r] = min(f[l][r], f[l][j] + f[j + 1][r] + s[r] - s[l - 1]);
        }

    printf("%d\n", f[1][n]);

    return 0;
}