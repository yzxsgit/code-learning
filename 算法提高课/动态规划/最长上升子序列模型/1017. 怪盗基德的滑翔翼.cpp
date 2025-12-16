#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;
int f[N], a[N], g[N];
int n, k;

int main()
{
    scanf("%d", &k);
    while (k--)
    {
        memset(a, 0, sizeof a);
        memset(f, 0, sizeof f);
        memset(g, 0, sizeof g);
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
            scanf("%d", &a[i]);

        for (int i = 1; i <= n; i++)
            for (int j = 0; j < i; j++)
                if (a[j] < a[i])
                    f[i] = max(f[i], f[j] + 1);
        for (int i = n; i; i--)
            for (int j = n + 1; j > i; j--)
                if (a[j] < a[i])
                    g[i] = max(g[i], g[j] + 1);

        int res = 0;
        for (int i = 1; i <= n; i++)
            res = max(f[i], res);
        for (int i = 1; i <= n; i++)
            res = max(g[i], res);

        printf("%d\n", res);
    }

    return 0;
}