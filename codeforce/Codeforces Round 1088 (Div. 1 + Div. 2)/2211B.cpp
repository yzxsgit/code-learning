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

const int mod = 676767677;

void solve()
{
    int x, y;
    cin >> x >> y;

    int s = abs(x - y);
    int minn = 0;

    if (s == 0)
    {
        minn = 1;
    }
    else
    {
        for (int i = 1; i * i <= s; i++)
        {
            if (s % i == 0)
            {
                minn++;
                if (s != i * i)
                {
                    minn++;
                }
            }
        }
    }

    cout << minn % mod << '\n';

    bool first = true;
    for (int i = 0; i < x; i++)
    {
        if (!first)
            cout << " ";
        cout << 1;
        first = false;
    }
    for (int i = 0; i < y; i++)
    {
        if (!first)
            cout << " ";
        cout << -1;
        first = false;
    }
    cout << "\n";
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