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

    i64 a, b, n, m, L;
    cin >> a >> b >> m >> n >> L;

    i64 x, y;
    i64 d = exgcd(m - n, L, x, y);

    if ((b - a) % d)
        cout << "Impossible\n";
    else
    {
        x *= (b - a) / d;
        i64 t = abs(L / d);
        cout << (x % t + t) % t << '\n';
    }

    return 0;
}