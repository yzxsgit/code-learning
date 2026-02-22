#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

int x, y;

void solve()
{
    int n;
    cin >> n >> x >> y;
    int loss = x - y;
    vector<int> a(n);
    i64 res = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i] / x;
    }

    for (int i = 0; i < n; i++)
    {
        i64 tmp = a[i] + (sum - a[i] / x) * y;
        res = max(res, tmp);
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