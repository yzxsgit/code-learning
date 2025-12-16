#include <iostream>

using namespace std;
const int N = 1010;
int n;
int a[N];
int f[N], g[N];

int main()
{
    scanf("%d",&n);
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
        res = max(res, f[i] + g[i] - 1);

    printf("%d\n", res);

    return 0;
}