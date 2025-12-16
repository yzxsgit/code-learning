#include <iostream>

using namespace std;
typedef long long ll;
const int mod = 998244353, N = 1e6 + 10;
int a[N];
int gcd(int x,int y)
{
    return x % y == 0 ? y : gcd(y, x % y);
}
int n;
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    ll res = 0;
    for (int i = 1; i <= n; i++)
    {
        ll ans = i * a[i],tmp = a[i];
        for (int j = i + 1; j <= n; j++)
        {
            tmp = gcd(tmp, a[j]);
            ans = (ans + tmp * j) % mod;
        }
        res = (res + i * ans) % mod;
    }

    cout << res % mod<< endl;

    return 0;
}