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
    string a, b;
    cin >> a >> b;

    int res = 1e8;
    int tmp;

    int n = a.size(), m = b.size();
    for (int j = 0; j < m; j++)
    {
        tmp = 0;
        int k = j;
        for (int i = 0; i < n && k < m; i++)
        {
            if (a[i] == b[k])
            {
                k++;
                tmp++;
            }
        }
        res = min(res, (n + m - tmp));
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