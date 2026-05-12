#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <functional>
#include <array>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

void solve()
{
    int x, y;
    cin >> x >> y;

    if (x > y)
    {
        cout << "NO\n";
        return;
    }


    if (x == 0)
    {
        if (y % 2 == 0)
        {
            cout << "NO\n";
            return;
        }
        cout << "YES\n";
        for (int i = 2; i <= y; i++)
        {
            cout << 1 << ' ' << i << '\n';
        }
        return;
    }

    cout << "YES\n";

    for (int i = 1; i < x * 2; i++)
    {
        cout << i << ' ' << i + 1 << '\n';
    }

    int rem = y - x;
    int idx = 2 * x + 1;

    while (rem--)
    {
        cout << 2 * x << ' ' << idx++ << '\n';
    }
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