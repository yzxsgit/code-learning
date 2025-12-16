#include <bits/stdc++.h>
using namespace std;

const int N = 60, mod = 998244353;

int n, m, k;
long long f[N][N * N];

int main()
{
    cin >> n >> m >> k;
    for (int i = 1; i <= m; i++)
        f[1][i] = 1;

    for (int i = 2; i <= n; i++)
    {
        for (int j = i; j <= k; j++)
        {
            for (int t = 1; t <= min(j - i + 1, m); t++)
            {
                f[i][j] = (f[i][j] + f[i - 1][j - t]) % mod;
            }
        }
    }

    long long ans = 0;
    for (int i = 1; i <= k;i++)
        ans = (ans + f[n][i]) % mod;
    
    printf("%lld\n", ans);

    return 0;
}