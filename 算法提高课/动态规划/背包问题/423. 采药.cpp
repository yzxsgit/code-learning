#include <iostream>

using namespace std;
const int N = 1110;
int a[N], w[N];
int t, m;
int f[N];
int main()
{
    scanf("%d%d", &t, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d%d", &a[i], &w[i]);

    for (int i = 1; i <= m; i++)
        for (int j = t; j >= a[i]; j--)
            f[j] = max(f[j - a[i]] + w[i], f[j]);

    printf("%d\n", f[t]);

    return 0;
}