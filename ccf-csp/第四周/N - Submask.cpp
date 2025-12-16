#include <bits/stdc++.h>
using namespace std;

long long w[20];
long long n;

int main()
{
    cin >> n;
    int cnt = 0, x = 0;
    long long res = 1;
    while (n >> x)
    {
        if (n >> x & 1)
            w[cnt++] = x;
        x++;
    }
    for (int i = 0; i < 1 << cnt; i++)
    {
        long long ans = 0;
        for (int j = 0; j < cnt; j++)
        {
            ans += (i >> j & 1) * (res << w[j]);
        }

        printf("%lld\n", ans);
    }

    return 0;
}