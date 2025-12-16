#include <bits/stdc++.h>
using namespace std;
const int N = 1e3 + 10;
int a[N];
int f[N];
int n;
int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j < i; j++)
            if (a[j] < a[i])
                f[i] = max(f[i], f[j] + 1);

    int ans = 0;

    for (int i = 1; i <= n; i++)
        ans = max(f[i], ans);

    printf("%d", ans + 1);

    return 0;
}