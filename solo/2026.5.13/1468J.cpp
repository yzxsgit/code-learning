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
    int u, v, val;

    bool operator<(const Edge &t)
    {
        return val < t.val;
    }
};

void solve()
{
    int n, m, k;
    cin >> n >> m >> k;

    vector<Edge> edge;

    int minn = -1, id = -1;
    for (int i = 0; i < m; i++)
    {
        int u, v, val;
        cin >> u >> v >> val;
        edge.push_back({u, v, val});
        if (id == -1 || minn > abs(val - k) || minn == abs(val - k) && val > edge[id].val)
        {
            id = i;
            minn = abs(val - k);
        }
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
        int cnt = 1;

        st[id] = true;
        auto [u, v, val] = edge[id];
        fa[u] = v;

        for (int i = 0; i < m && cnt < n - 1; i++)
        {
            if (!st[i])
            {
                auto [u, v, val] = edge[i];

                int nu = find(u), nv = find(v);

                if (nu != nv)
                {
                    st[i] = true;
                    nu = nv;
                    cnt++;
                }
            }
        }
    };
    kruskal();

    int res = minn;

    for (int i = m - 1; i >= 0; i--)
        if (st[i] && i != id)
        {
            if (edge[i].val > k)
                res += edge[i].val - k;
            else
                break;
        }

    // for (int i = 0; i < m; i++)
    //     if (st[i])
    //         cout << i << ' ';
    // cout << '\n';

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