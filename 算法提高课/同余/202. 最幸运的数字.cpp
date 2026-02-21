#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

i64 qmi(i64 a, i64 k, i64 p)
{
    i64 res = 1;
    while (k)
    {
        if (k & 1)
        {
            res = (__int128)res * a % p;
        }
        a = (__int128)a * a % p;
        k >>= 1;
    }

    return res;
}

i64 get_eular(i64 C)
{
    i64 res = C;
    for (int i = 2; i <= C / i; i++)
    {
        if (C % i == 0)
        {
            while (C % i == 0)
                C /= i;
            res = res / i * (i - 1);
        }
    }
    if (C > 1)
    {
        res = res / C * (C - 1);
    }
    return res;
}


void solve(int L, int T)
{
    i64 d = gcd(8, L);
    i64 C = L / d * 9;

    i64 phi = get_eular(C);

    i64 res = 1e18;
    if (C % 2 == 0 || C % 5 == 0)
        res = 0;
    else
    {
        for (i64 i = 1; i * i <= phi; i++)
        {
            if (phi % i == 0)
            {
                if (qmi(10, i, C) == 1)
                    res = min(res, i);
                if (qmi(10, phi / i, C) == 1)
                    res = min(res, phi / i);
            }
        }
    }

    cout << "Case " << T << ": " << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T = 1;
    int L;
    while (cin >> L && L)
    {
        solve(L, T++);
    }
    return 0;
}