#include <iostream>

using namespace std;
const int N = 11, M = 16;
int w[N][M];
int f[N][M];
int n, m;
int ans[N];

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> w[i][j];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k <= j; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - k] + w[i][k]);

    cout<<f[n][m]<<endl;

    int j = m;
    for (int i = n; i; i--)
        for (int k = 0; k <= j; k++)
            if (f[i][j] == f[i - 1][j - k] + w[i][k])
            {
                ans[i] = k;
                j -= k;
                break;
            }

    for (int i = 1; i <= n; i++)
        printf("%d %d\n", i, ans[i]);

    return 0;
}