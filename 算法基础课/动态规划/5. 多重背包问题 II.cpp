#include <bits/stdc++.h>
using namespace std;
const int N = 25000;
int v[N], w[N];
int f[N];
int n, m, cnt;
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        int k = 1;
        while (k <= c)
        {
            cnt++;
            v[cnt] = a * k;
            w[cnt] = b * k;
            c -= k;
            k *= 2;
        }
        if(c)
        {
            cnt++;
            v[cnt] = a * c;
            w[cnt] = b * c;
        }
    }

    n = cnt;

    for (int i = 1; i <= n; i++)
        for (int j = m; j >= v[i]; j--)
            f[j] = max(f[j], f[j - v[i]] + w[i]);

    printf("%d\n", f[m]);

    return 0;
}