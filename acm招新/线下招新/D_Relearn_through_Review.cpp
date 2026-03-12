#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

i64 gcd(i64 a, i64 b)
{
    return b ? gcd(b, a % b) : a;
}

void solve()
{
    int n;
    i64 k;
    cin >> n >> k;
    vector<i64> a(n + 1), g(n + 1), suf(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];

    g[1] = a[1];
    for (int i = 2; i <= n; i++)
        g[i] = gcd(g[i - 1], a[i]);

    suf[n] = a[n];
    for (int i = n - 1; i > 0; i--)
        suf[i] = gcd(suf[i + 1], a[i]);

    i64 res = g[n];
    i64 mid = a[1];
    // g[0] = 0; 

    for (int i = 1; i <= n; i++)
    {
        if (g[i] != g[i - 1])
        {
            mid = g[i - 1];

            for (int j = i; j <= n; j++)
            {
                mid = gcd(mid, a[j] + k);

                if (j < n)
                {
                    res = max(res, gcd(mid, suf[j + 1]));
                }
                else
                {
                    res = max(res, mid);
                }
            }
        }
    }
    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}