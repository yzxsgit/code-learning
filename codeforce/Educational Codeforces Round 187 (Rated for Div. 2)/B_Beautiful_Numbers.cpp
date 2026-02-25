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

void solve()
{
    i64 x;
    cin >> x;

    vector<int> a;

    int tmp = 0;
    int first;
    while (x)
    {
        tmp += (x % 10);
        if (x < 10)
        {
            first = x;
        }
        a.push_back(x % 10);
        x /= 10;
    }
    bool flag = true;

    sort(a.begin(), a.end());

    int res = 0;
    for (int i = a.size() - 1; i >= 0; i--)
    {
        if (tmp >= 10)
        {
            if (first == a[i] && flag && a[i - 1] != a[i])
            {
                tmp -= (a[i] - 1);
                flag = false;
                res++;
            }
            else
            {
                tmp -= a[i];
                res++;
            }
        }
        else
        {
            break;
        }
    }

    cout << res << '\n';
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