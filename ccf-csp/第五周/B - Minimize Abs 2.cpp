#include <bits/stdc++.h>
using namespace std;

long long d;
int main()
{
    cin >> d;

    long long ans = LONG_LONG_MAX;
    long long max_val = sqrt(d) + 1;

    for (long long x = 0; x <= max_val; x++)
    {
        long long y = sqrt(d - x * x);
        ans = min(ans, min(abs(x * x + y * y - d), abs(x * x + (y + 1) * (y + 1) - d)));
    }

    printf("%lld", ans);

    return 0;
}