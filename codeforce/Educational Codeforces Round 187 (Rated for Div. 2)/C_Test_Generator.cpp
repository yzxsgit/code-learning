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

i64 lowbit(i64 x)
{
    return x & -x;
}

i64 s, m;

bool check(i64 n)
{
    i64 rem = s;

    for (int j = 60; j >= 0; j--)
    {
        if ((m >> j) & 1)
        {
            i64 use = min(n, rem >> j);
            rem -= use << j;
        }
    }

    return rem == 0;
}

void solve()
{
    cin >> s >> m;

    i64 minn = lowbit(m);
    if (s % minn != 0)
    {
        cout << -1 << '\n';
        return;
    }

    vector<i64> a;

    i64 l = 1, r = s;

    while (l < r)
    {
        i64 mid = l + r >> 1;
        if (check(mid))
        {
            r = mid;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << l << '\n';
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