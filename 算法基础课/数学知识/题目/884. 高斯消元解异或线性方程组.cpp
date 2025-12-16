#include <bits/stdc++.h>
using namespace std;
const int N = 110;
int n;
int a[N][N];
int gauss_xor()
{
    int r, c;
    for (c = 0, r = 0; c < n; c++)
    {
        int t = r;
        for (int i = r + 1; i < n; i++)
            if (!a[t][c] && a[i][c])
                t = i;

        if (!a[t][c])
            continue;

        for (int i = c; i <= n; i++)
            swap(a[r][i], a[t][i]);

        for (int i = r + 1; i < n; i++)
            if (a[i][c])
                for (int j = c; j <= n; j++)
                    a[i][j] ^= a[r][j];

        r++;
    }
    if (r < n)
    {
        for (int i = r; i < n; i++)
            if (a[i][n])
                return 0;
        return 1;
    }

    for (int i = n - 1; i > 0; i--)
        for (int j = i + 1; j <= n; j++)
            a[i][n] ^= a[i][j] * a[j][n];

    return 2;
}
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= n; j++)
            scanf("%d", &a[i][j]);

    int flag = gauss_xor();

    if (flag == 0)
        printf("No solution");
    else if (flag == 1)
        printf("Multiple sets of solutions");
    else
    {
        for (int i = 0; i < n; i++)
            printf("%d\n", a[i][n]);
    }

    return 0;
}