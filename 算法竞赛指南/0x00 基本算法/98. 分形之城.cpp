#include <iostream>
#include <cmath>

using namespace std;
typedef long long LL;
typedef pair<LL, LL> PLL;

PLL calc(LL n,LL m)
{
    if(n == 0)
        return {0, 0};
    LL len = 1ll << (n - 1);
    LL cnt = 1ll << (n - 1) * 2;
    LL cnk = m / cnt;
    LL idx = m % cnt;
    PLL pos = calc(n - 1, idx);
    LL x = pos.first, y = pos.second;

    if(cnk == 0)
        return {y, x};
    if(cnk == 1)
        return {x, y + len};
    if(cnk == 2)
        return {x + len, y + len};
    if(cnk == 3)
        return {len * 2 - y - 1, len - x - 1};
}

int main()
{
    int times;
    scanf("%d", &times);
    while (times--)
    {
        LL n, a, b;
        scanf("%lld%lld%lld", &n, &a, &b);
        PLL pa = calc(n, a - 1);
        PLL pb = calc(n, b - 1);
        double x = pa.first - pb.first, y = pa.second - pb.second;
        printf("%.0lf\n", sqrt(x * x + y * y) * 10.00);
    }

    return 0;
}