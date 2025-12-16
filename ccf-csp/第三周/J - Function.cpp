#include <bits/stdc++.h>
using namespace std;

const int N = 21;

long long w[N][N][N];
long long a, b, c;

int main()
{
    for (int i = 0; i <= 20; i++)
        for (int j = 0; j <= 20; j++)
            for (int k = 0; k <= 20; k++)
                if (i == 0 || j == 0 || k == 0)
                    w[i][j][k] = 1;

    for (int i = 1; i <= 20; i++)
        for (int j = 1; j <= 20; j++)
            for (int k = 1; k <= 20; k++)
                if (i < j && j < k)
                    w[i][j][k] = w[i][j][k - 1] + w[i][j - 1][k - 1] - w[i][j - 1][k];
                else
                    w[i][j][k] = w[i - 1][j][k] + w[i - 1][j - 1][k] + w[i - 1][j][k - 1] - w[i - 1][j - 1][k - 1];

    while (cin >> a >> b >> c, !(a == -1 && b == -1 && c == -1))
    {
        printf("w(%lld, %lld, %lld)", a, b, c);
        if (a <= 0 || b <= 0 || c <= 0)
        {
            printf(" = 1\n");
            continue;
        }

        if (a > 20 || b > 20 || c > 20)
        {
            printf(" = %lld\n", w[20][20][20]);
            continue;
        }

        printf(" = %lld\n", w[a][b][c]);
    }

    return 0;
}