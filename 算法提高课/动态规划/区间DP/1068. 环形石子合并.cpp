#include <iostream>
#include <cstring>

using namespace std;
const int N = 410;

int n;
int w[N];
int s[N];
int f[N][N], g[N][N];

int dfs_min(int l, int r)
{
    if (f[l][r] != 0x3f3f3f3f)
        return f[l][r];
    if (l == r)
        return f[l][r] = 0;

    for (int k = l; k < r; k++)
        f[l][r] = min(f[l][r], dfs_min(l, k) + dfs_min(k + 1, r) + s[r] - s[l - 1]);

    return f[l][r];
}

int dfs_max(int l, int r)
{
    if (g[l][r] != -1044266559)
        return g[l][r];
    if (l == r)
        return g[l][r] = 0;

    for (int k = l; k < r; k++)
        g[l][r] = max(g[l][r], dfs_max(l, k) + dfs_max(k + 1, r) + s[r] - s[l - 1]);

    return g[l][r];
}

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        w[i + n] = w[i];
    }

    for (int i = 1; i <= 2 * n; i++)
        s[i] = s[i - 1] + w[i];

    memset(f, 0x3f, sizeof f);
    memset(g, -0x3f, sizeof g);

    int minv = 0x3f3f3f3f, maxv = -0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
    {
        minv = min(minv, dfs_min(i, i + n - 1));
        maxv = max(maxv, dfs_max(i, i + n - 1));
    }

    cout << minv << "\n"
         << maxv << "\n";
    return 0;
}