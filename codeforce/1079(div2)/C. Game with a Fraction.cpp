#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

void solve()
{
    i64 p, q, d;
    cin >> p >> q;
    d = p - q;
    bool res; // true:Alice;

    if (p + 2 * d < 0 || p >= q) res = true;
    else if (p + 2 * d == 0) res = false;
    else
    {
        d = abs(d);
        if (p >= 2 * d) res = false;
        else res = true;
    }
    cout << (res ? "Alice" : "Bob") << '\n';
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