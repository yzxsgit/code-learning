#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <cmath>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

void solve()
{
    i64 x, y;
    cin >> x >> y;
    if (y > 0)
    {
        if (y > x / 2)
        {
            cout << "NO\n";
            return;
        }

        x -= y * 2;
    }
    else if (y < 0)
    {
        if (abs(y) > x / 4)
        {
            cout << "NO\n";
            return;
        }
        x -= abs(y) * 4;
    }
    if (x % 3 == 0)
    {
        cout << "YES\n";
    }
    else
    {
        cout << "NO\n";
    }
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