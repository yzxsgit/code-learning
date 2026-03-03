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

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n), b(n);
    int tmp = -1, minn = 1e9 + 10, maxx = -1;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    for (int i = 0; i < n; i++)
    {
        if (b[i] == -1)
        {
            minn = min(minn, a[i]);
            maxx = max(maxx, a[i]);
        }
        else
        {
            if (tmp == -1)
            {
                tmp = a[i] + b[i];
            }
            else if (tmp != a[i] + b[i])
            {
                cout << 0 << '\n';
                return;
            }
        }
    }

    int res = max(0, minn + k - maxx + 1);
    if (tmp == -1)
        cout << res << '\n';
    else
        cout << ( maxx == -1 || (tmp <= k + minn && tmp >= maxx) ? 1 : 0) << '\n';
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