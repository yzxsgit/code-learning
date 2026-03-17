#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <math.h>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;


i64 lcm(i64 a, i64 b)
{
    return a / __gcd(a, b) * b;
}

i64 res(i64 a, i64 y, i64 b, i64 c)
{
    i64 one, two, three;
    three = y / lcm(lcm(a, b), c);
    two = y / lcm(a, b) + y / lcm(a, c) - 2 * three;
    one = y / a - two - three;

    return one * 6 + two * 3 + three * 2;
}

void solve()
{
    i64 a, b, c, d;
    cin >> a >> b >> c >> d;

    cout << res(a, d, b, c) << ' ';
    cout << res(b, d, a, c) << ' ';
    cout << res(c, d, a, b) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}