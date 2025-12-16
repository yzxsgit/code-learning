#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;
int f[N], w[N][N];
int t, r, c;
int main()
{
    scanf("%d", &t);
    while (t--)
    {
        memset(f, 0, sizeof f);
        scanf("%d %d", &r, &c);
        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                scanf("%d", &w[i][j]);

        for (int i = 1; i <= r; i++)
            for (int j = 1; j <= c; j++)
                f[j] = max(f[j-1], f[j]) + w[i][j];

        printf("%d\n", f[c]);
    }

    return 0;
}