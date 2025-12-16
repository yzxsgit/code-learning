#include <bits/stdc++.h>
using namespace std;

int qmi(int a, int k, int p)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = (long long)res * a % p;
        a = (long long)a * a % p;
        k >>= 1;
    }

    return res;
}

int C(int a, int b, int p)
{
    if (b > a)
        return 0;
    else
    {
        int res = 1;
        for (int i = 1, j = a; i <= b; i++, j--)
        {
            res = (long long)res * j % p;
            res = (long long)res * qmi(i, p - 2, p) % p;
        }
        return res;
    }
}

long long lucas(long long a, long long b, int p)
{
    if (a < p && b < p)
        return C(a, b, p);
    else
        return C(a % p, b % p, p) * lucas(a / p, b / p, p) % p;
}
int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int p;
        long long a, b;
        cin >> a >> b >> p;
        printf("%lld\n", lucas(a, b, p));
    }
    return 0;
}