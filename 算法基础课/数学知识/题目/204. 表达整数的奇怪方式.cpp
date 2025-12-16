#include <bits/stdc++.h>
using namespace std;
const int N = 30;
typedef long long LL;
int n;
LL exgcd(LL a, LL b, LL &x, LL &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }

    LL d = exgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
int main()
{
    scanf("%d", &n);

    LL a1, m1;
    cin >> a1 >> m1;

    LL a2, m2;
    bool flag = true;

    for (int i = 0; i < n - 1; i++)
    {
        cin >> a2 >> m2;
        
        LL k1, k2;
        LL d = exgcd(a1, a2, k1, k2);
        if ((m2 - m1) % d)
        {
            flag = false;
            break;
        }

        k1 *= (m2 - m1) / d;
        LL t = a2 / d;
        k1 = (k1 % t + t) % t;

        m1 = a1 * k1 + m1;
        a1 = abs(a1 / d * a2);
    }

    if (flag)
    {
        printf("%lld\n", (m1 % a1 + a1) % a1);
    }
    else
        printf("-1\n");

    return 0;
}