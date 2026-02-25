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

int p[3];

void solve()
{
    for (int i = 0; i < 3; i++)
        cin >> p[i];

    int sum_p = 0;
    for (int i = 0; i < 3; i++)
        sum_p += p[i];

    if (sum_p % 2)
    {
        cout << -1 << '\n';
        return;
    }

    int res = 0;
    
    if (p[0] + p[1] < p[2])
        res = p[0] + p[1];
    else
    {
        res = p[2] + (sum_p - p[2] * 2) / 2;
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