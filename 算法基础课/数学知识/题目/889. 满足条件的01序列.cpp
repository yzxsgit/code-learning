#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int qmi(int a,int k,int p)
{
    int res = 1;
    while(k)
    {
        if(k & 1)
            res = (long long)res * a % p;
        a = (long long)a * a % p;
        k >>= 1;
    }

    return res;
}
int main()
{
    int n;
    cin >> n;
    int ans = 1;
    int a = 2 * n, b = n;
    for (int i = a; i > a - b; i--)
        ans = (long long)ans * i % mod;
    for (int i = b; i > 0; i--)
        ans = (long long)ans * qmi(i, mod - 2, mod) % mod;

    ans = (long long)ans * qmi(n + 1, mod - 2, mod) % mod;

    printf("%d\n", ans);

    return 0;
}