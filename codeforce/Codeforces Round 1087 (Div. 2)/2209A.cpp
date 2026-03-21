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
    int n;
    i64 c, k;

    cin >> n >> c >> k;
    vector<i64> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    for (int i = 0; i < n; i++)
    {
        if (a[i] <= c)
        {
            i64 tmp = min(k, c - a[i]);
            c += a[i] + min(k, tmp);
            k = k - tmp;
        }
    }

    cout << c << '\n';
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