#include <iostream>

using namespace std;
const int N = 11;
int f[N * 2][N][N], w[N][N];


int main()
{
    int n;
    scanf("%d", &n);
    int a, b, c;
    while (cin >> a >> b >> c, a || b || c)
        w[a][b] = c;

    for (int k = 1; k <= 2 * n; k++)
        for (int i1 = 1; i1 <= n; i1++)
            for (int i2 = 1; i2 <= n; i2++)
            {
                int j1 = k - i1, j2 = k - i2;
                if (j1 >= 1 && j1 <= n && j2 >= 1 && j2 <= n)
                {
                    int t = w[i1][j1];
                    if(j1 != j2)
                        t += w[i2][j2];
                    int &x = f[k][i1][i2];
                    x = max(f[k - 1][i1 - 1][i2 - 1] + t, x);
                    x = max(f[k - 1][i1 - 1][i2] + t, x);
                    x = max(f[k - 1][i1][i2 - 1] + t, x);
                    x = max(f[k - 1][i1][i2] + t, x);
                }
            }

    printf("%d\n", f[n * 2][n][n]);

    return 0;
}