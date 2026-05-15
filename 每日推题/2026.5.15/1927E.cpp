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
    int n, k;
    cin >> n >> k;

    int t = n / k;

    vector<int> res(n + 1);
    bool flag = true;
    int l = 1, r = n;
    for (int i = 1; i <= k; i++)
    {
        if (flag)
        {
            for (int j = 0; j <= t; j++)
            {
                int pos = i + j * k;
                if (pos > n)
                    break;
                res[pos] = l++;
            }
            flag = false;
        }
        else
        {
            for (int j = 0; j <= t; j++)
            {
                int pos = i + j * k;
                if (pos > n)
                    break;
                res[pos] = r--;
            }
            flag = true;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << res[i] << ' ';
    cout << '\n';
    return;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T = 1;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}