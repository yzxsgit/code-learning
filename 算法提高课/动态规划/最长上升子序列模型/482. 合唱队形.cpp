#include <iostream>

using namespace std;
const int N = 110;
int n;
int t[N];
int f[N], g[N];

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> t[i];

    for (int i = 1; i <= n; i++)
        for (int j = 0; j < i; j++)
            if(t[j] < t[i])
                f[i] = max(f[i], f[j] + 1);

    for (int i = n; i;i--)
        for (int j = n + 1; j > i; j--)
            if (t[j] < t[i])
                g[i] = max(g[i], g[j] + 1);

    int res = 0x3f3f3f3f;
    for (int i = 1; i <= n; i++)
        res = min(res, n - f[i] - g[i] + 1);

    printf("%d\n", res);

    return 0;
}