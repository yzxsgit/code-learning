#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <functional>
#include <iomanip>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

void solve()
{
    int n;
    cin >> n;

    vector<PII> a(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i].first >> a[i].second;
    }

    double res = 0;

    for (int i = n; i >= 1; i--)
    {
        double skip = res;
        double take = a[i].first + res * (1.0 - a[i].second / 100.0);

        res = max(skip, take);
    }

    cout << fixed << setprecision(10) << res << "\n";
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