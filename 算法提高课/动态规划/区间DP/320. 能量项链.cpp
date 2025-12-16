#include <iostream>

using namespace std;

const int N = 410;

int f[N][N];
int w[N];
int n;

int dfs(int l, int r)
{
    if(f[l][r] != 0)
        return f[l][r];
    if(l == r)
        return f[l][r] = 0;

    for (int k = l + 1; k < r; k++)
        f[l][r] = max(f[l][r], dfs(l, k) + dfs(k , r) + w[l] * w[k] * w[r]);

    return f[l][r];
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> w[i];
        w[i + n] = w[i];
    }

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, dfs(i, i + n));

    cout << res << "\n";

    return 0;
}