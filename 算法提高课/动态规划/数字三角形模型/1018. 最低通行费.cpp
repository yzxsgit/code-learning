#include <iostream>

using namespace std;

const int N = 110, INF = 0x3f3f3f3f;
int f[N][N], w[N][N];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &w[i][j]);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
        {
            if (i == 1 && j == 1)
                f[i][j] = w[i][j];
            else
            {
                f[i][j] = INF;
                if (i != 1)
                    f[i][j] = min(f[i - 1][j] + w[i][j], f[i][j]);
                if (j != 1)
                    f[i][j] = min(f[i][j - 1] + w[i][j], f[i][j]);
            }
        }

    printf("%d", f[n][n]);

    return 0;
}