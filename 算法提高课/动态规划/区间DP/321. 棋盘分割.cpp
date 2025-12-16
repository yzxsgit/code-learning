#include <iostream>
#include <cstring>
#include <cmath>

using namespace std;

const int N = 16, M = 9;
double INF = 1e9;
double X;

int s[M][M];
double f[M][M][M][M][N];
int n, m = 8;

double get(int x1, int y1, int x2, int y2)
{
    double sum = (s[x2][y2] - s[x1 - 1][y2] - s[x2][y1 - 1] + s[x1 - 1][y1 - 1]) - X;

    return (double)sum * sum / n;
}

double dp(int x1, int y1, int x2, int y2, int k)
{
    double &v = f[x1][y1][x2][y2][k];
    if (v >= 0)
        return v;
    if(k == 1)
        return v = get(x1, y1, x2, y2);

    v = INF;

    for (int i = x1; i < x2; i++)
    {
        v = min(v, dp(x1, y1, i, y2, k - 1) + get(i + 1, y1, x2, y2));
        v = min(v, dp(i + 1, y1, x2, y2, k - 1) + get(x1, y1, i, y2));
    }

    for (int i = y1; i < y2; i++)
    {
        v = min(v, dp(x1, y1, x2, i, k - 1) + get(x1, i + 1, x2, y2));
        v = min(v, dp(x1, i + 1, x2, y2, k - 1) + get(x1, y1, x2, i));
    }

    return v;
}

int main()
{
    cin >> n;
    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= m; j++)
        {
            cin >> s[i][j];
            s[i][j] += s[i - 1][j] + s[i][j - 1] - s[i - 1][j - 1];
        }

    X = (double)s[m][m] / n;
    memset(f, -1, sizeof f);
    printf("%.3lf\n", sqrt(dp(1, 1, m, m, n)));

    return 0;
}
