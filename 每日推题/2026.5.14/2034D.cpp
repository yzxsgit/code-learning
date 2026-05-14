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
    int n;
    cin >> n;

    vector<int> a(n + 1), cnt(3, 0);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    auto bel = [&](int i) -> int
    {
        if (i <= cnt[0])
            return 0;
        if (i <= cnt[0] + cnt[1])
            return 1;
        return 2;
    };

    vector<int> pos[3][3];

    for (int i = 1; i <= n; i++)
        pos[a[i]][bel(i)].push_back(i);

    vector<PII> ans;

    auto add = [&](int i) -> void
    {
        pos[a[i]][bel(i)].push_back(i);
    };

    auto del = [&](int i) -> void
    {
        pos[a[i]][bel(i)].pop_back();
    };

    auto work = [&](int x, int y) -> void
    {
        ans.push_back({x, y});

        del(x);
        del(y);

        swap(a[x], a[y]);

        add(x);
        add(y);
    };

    auto fix = [&](int x) -> void
    {
        while (!pos[1][x].empty() || !pos[2 - x][x].empty())
        {
            if (pos[1][x].empty())
            {
                if (!pos[1][2 - x].empty())
                    work(pos[2 - x][x].back(), pos[1][2 - x].back());
                else
                    work(pos[2 - x][x].back(), pos[1][1].back());
            }

            if (!pos[x][1].empty())
                work(pos[1][x].back(), pos[x][1].back());
            else
                work(pos[1][x].back(), pos[x][2 - x].back());
        }
    };

    if (cnt[0] <= cnt[2])
    {
        fix(0);
        fix(2);
    }
    else
    {
        fix(2);
        fix(0);
    }

    cout << ans.size() << '\n';
    for (auto [x, y] : ans)
        cout << x << ' ' << y << '\n';
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