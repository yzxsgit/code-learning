#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10, mod = 1e9 + 7;
int fact[N], infact[N];

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

void init()
{
    fact[0] = infact[0] = 1;
    for (int i = 1; i <= 1e5; i++)
    {
        fact[i] = (long long)fact[i - 1] * i % mod;
        infact[i] = (long long)infact[i - 1] * qmi(i, mod - 2, mod) % mod;
    }
}
int main()
{
    init();
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", (long long)fact[a] * infact[b] % mod * infact[a - b] % mod);
    }

    return 0;
}