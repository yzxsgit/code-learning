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
using PII = pair<int,int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, m;
    cin >> n >> m;

    vector<int> a(n + 1), b(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];
    vector<int> d(1e6, 2e9);

    int Dmax = 2e9;
    int Amin = 2e9;

    for (int i = 1; i <= n; i++)
    {
        int D = a[i] - b[i];
        d[a[i]] = min(d[i], D);
        if (D < Dmax)
        {
            Dmax = D;
            Amin = a[i];
        }
        else if (D ==  Dmax)
        {
            Amin = min(a[i], Amin);
        }

        for (int i = 1; i <= 1e6; i++)
        {
            d[i] = min(d[i], d[i - 1]);
        }
    }

    vector<i64> f(1e6 + 10);

    for (int i = 1; i <= 1e6; i++)
    {
        if (d[i] <= i)
        {
            f[i] = 1 + f[i - d[i]];
        }
        else
        {
            f[i] = 0;
        }
    }
    i64 res = 0;

    while (m--)
    {
        i64 c;
        cin >> c;
        i64 tmp = 0;

        if (c > 1e6)
        {
            i64 k = (c - Amin) / Dmax + 1;
            tmp += k;
            c -= k * Dmax;
        }

        tmp += f[c];

        res += tmp * 2;
    }

    cout << res << '\n';

    return 0;
}