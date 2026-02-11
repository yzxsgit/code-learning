#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

int d(int x)
{
    int res = 0;
    while (x)
    {
        res += x % 10;
        x /= 10;
    }
    return res;
}

void solve()
{
    int x;
    cin >> x;
    if (x % 9 != 0)
    {
        cout << 0 << '\n';
        return;
    }
    int cnt = 0;
    for (int y = x; y <= x + 100; y++)
        if (y - d(y) == x)
            cnt++;
    cout << cnt << '\n';
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