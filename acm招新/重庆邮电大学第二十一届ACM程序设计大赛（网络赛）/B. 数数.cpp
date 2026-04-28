#include <bits/stdc++.h>
using namespace std;

static const int MOD = 1000000007;

long long mod_pow(long long a, long long e)
{
    long long r = 1;
    while (e)
    {
        if (e & 1)
            r = r * a % MOD;
        a = a * a % MOD;
        e >>= 1;
    }
    return r;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n1, n2, n3, n4;
    cin >> n1 >> n2 >> n3 >> n4;

    int t = n1 + n2;
    int maxN = n1 + n2 + n3 + n4 + 5;

    vector<long long> fac(maxN + 1), ifac(maxN + 1), pw2(t + 3);

    fac[0] = 1;
    for (int i = 1; i <= maxN; ++i)
        fac[i] = fac[i - 1] * i % MOD;
    ifac[maxN] = mod_pow(fac[maxN], MOD - 2);
    for (int i = maxN; i >= 1; --i)
        ifac[i - 1] = ifac[i] * i % MOD;

    pw2[0] = 1;
    for (int i = 1; i < (int)pw2.size(); ++i)
        pw2[i] = pw2[i - 1] * 2 % MOD;

    auto C = [&](int n, int k) -> long long
    {
        if (n < 0 || k < 0 || k > n)
            return 0;
        return fac[n] * ifac[k] % MOD * ifac[n - k] % MOD;
    };

    auto calc = [&](int a, int b, int m) -> long long
    {
        if (m == 0)
            return (a == 0 && b == 0) ? 1LL : 0LL;

        long long ans = 0;
        int D = a - b;

        for (int z = 0; z <= m; ++z)
        {
            int rem = m - z; 

            if ((rem + D) & 1)
                continue;

            int x = (rem + D) / 2;
            int y = (rem - D) / 2;
            if (x < 0 || y < 0)
                continue;

            int rest = a - x - z;
            if (rest < 0)
                continue;
            if (rest != b - y - z)
                continue;

            long long waysType = C(m, x) * C(m - x, y) % MOD;
            long long waysDir = pw2[z];
            long long waysLen = C(rest + m - 1, m - 1);

            ans = (ans + waysType * waysDir % MOD * waysLen) % MOD;
        }
        return ans;
    };

    if (t == 0)
    {
        if (n3 == 0 && n4 == 0)
            cout << 1 << '\n';
        else
            cout << calc(n3, n4, 1) << '\n';
        return 0;
    }

    vector<long long> f12(t + 1), f34(t + 2);
    for (int m = 0; m <= t; ++m)
        f12[m] = calc(n1, n2, m);
    for (int m = 0; m <= t + 1; ++m)
        f34[m] = calc(n3, n4, m);

    long long ans = 0;
    for (int b = 1; b <= t; ++b)
    {
        if (f12[b] == 0)
            continue;
        long long ways34 = (f34[b - 1] + 2 * f34[b] + f34[b + 1]) % MOD;
        ans = (ans + f12[b] * ways34) % MOD;
    }

    cout << ans % MOD << '\n';
    return 0;
}