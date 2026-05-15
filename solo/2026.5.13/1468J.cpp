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

struct Edge
{
    int u, v;
    i64 val;

    bool operator<(const Edge &t) const
    {
        return val < t.val;
    }
};

void solve()
{
    int n, m;
    i64 k;
    cin >> n >> m >> k;

    vector<Edge> edge;

    i64 minn = 4e18;
    for (int i = 0; i < m; i++)
    {
        int u, v, val;
        cin >> u >> v >> val;
        edge.push_back({u, v, val});
        minn = min(abs(k - val), minn);
    }

    sort(edge.begin(), edge.end());

    vector<int> fa(n + 1);

    for (int i = 1; i <= n; i++)
        fa[i] = i;

    function<int(int)> find = [&](int x) -> int
    {
        if (fa[x] != x)
            fa[x] = find(fa[x]);
        return fa[x];
    };

    vector<bool> st(m, false);

    auto kruskal = [&]() -> void
    {
        int cnt = 0;

        for (int i = 0; i < m && cnt < n - 1; i++)
        {
            auto [u, v, val] = edge[i];

            int nu = find(u), nv = find(v);

            if (nu != nv)
            {
                st[i] = true;
                fa[nu] = nv;
                cnt++;
            }
        }
    };
    kruskal();

    i64 res = 0;

    bool has_bigger = false;
    for (int i = m - 1; i >= 0; i--)
        if (st[i])
        {
            if (edge[i].val > k)
            {
                res += edge[i].val - k;
                has_bigger = true;
            }
        }

    if (!has_bigger)
        res += minn;

    cout << res << '\n';
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