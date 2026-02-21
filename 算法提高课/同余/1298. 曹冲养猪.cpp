#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

i64 exgcd(i64 a, i64 b, i64 &x, i64 &y)
{
    if (!b)
    {
        x = 1, y = 0;
        return a;
    }
    else
    {
        i64 d = exgcd(b, a % b, y, x);
        y -= a / b * x;
        return d;
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<i64> a(n), m(n);

    i64 M = 1;
    for (int i = 0; i < n; i++)
    {
        cin >> m[i] >> a[i];
        M *= m[i];
    }

    i64 res = 0;
    for (int i = 0; i < n; i++)
    {
        i64 p = M / m[i];
        i64 v, k;
        exgcd(p, m[i], v, k);
        res = (res +(__int128)a[i] * p * v) % M;
    }

    cout << (res % M + M) % M << '\n';

    return 0;
}