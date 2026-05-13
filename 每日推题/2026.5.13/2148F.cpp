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

    vector<vector<int>> a(n);

    int m = 0;
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;

        for (int j = 0; j < k; j++)
        {
            int x;
            cin >> x;
            a[i].push_back(x);
        }
        m = max(m, k);
    }

    int pos = 0;

    vector<int> res;

    auto better = [&](int x, int y)
    {
        int i = pos;
        while (i < (int)a[x].size() && i < (int)a[y].size())
        {
            if (a[x][i] != a[y][i])
                return a[x][i] < a[y][i];
            i++;
        }
        return a[x].size() < a[y].size(); 
    };

    auto find_min = [&]() -> int
    {
        int ans = -1;

        for (int i = 0; i < n; i++)
        {
            if ((int)a[i].size() <= pos)
                continue;

            if (ans == -1 || better(i, ans))
            {
                ans = i;
            }
        }
        return ans;
    };

    while (pos < m)
    {
        int idx = find_min();
        for (int i = pos; i < a[idx].size(); i++)
            res.push_back(a[idx][i]);

        pos = a[idx].size();
    }

    for (auto item : res)
        cout << item << ' ';
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