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
    i64 n, k, x;
    cin >> n >> k >> x;

    vector<i64> a(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    sort(a.begin(), a.end());

    auto check = [&](i64 d) -> bool
    {
        i64 cnt = 0;

        cnt += max(0LL, a[0] - d + 1);

        for (int i = 0; i < n - 1; i++)
        {
            i64 L = a[i] + d;
            i64 R = a[i + 1] - d;

            if (L <= R)
                cnt += R - L + 1;
            if (cnt >= k)
                return true;
        }

        cnt += max(0LL, x - (a[n - 1] + d) + 1);

        return cnt >= k;
    };

    i64 l = 0, r = 1e9 + 1;

    while (l < r)
    {
        i64 mid = l + r >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid;
    }

    vector<i64> res;

    {
        vector<pair<i64, i64>> pos;
        i64 d = l - 1;
        pos.push_back({0, a[0] - d});
        for (int i = 0; i < n - 1; i++)
        {
            i64 L = a[i] + d;
            i64 R = a[i + 1] - d;
            pos.push_back({L, R});
        }
        pos.push_back({a[n - 1] + d, x});

        for (auto [L, R] : pos)
        {
            for (i64 j = L; j <= R && res.size() < k; j++)
                if (res.empty() || res[res.size() - 1] != j)
                    res.push_back(j);
        }
    }

    for (i64 ans : res)
        cout << ans << ' ';
    cout << '\n';
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