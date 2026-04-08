#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <numeric>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

struct DSU
{
    vector<int> p;
    
    DSU(int n) : p(n + 1)
    {
        iota(p.begin(), p.end(), 0);
    }

    int find(int x)
    {
        if (p[x] != x)
            p[x] = find(p[x]);
        return p[x];
    }

    bool unite(int x, int y)
    {
        int px = find(x), py = find(y);
        if (px != py)
        {
            p[px] = py;
            return true;
        }
        return false;
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

void solve()
{
    int n, m;
    cin >> n >> m;
    DSU dsu(n);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        dsu.unite(a, b);
    }

    int res = 0;
    vector<bool> visited(n + 1, false);
    for (int i = 1; i <= n; i++)
    {
        if (dsu.p[i] == i)
            res++;
    }

    cout << res << '\n';
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
        cin.ignore();
    }
    return 0;
}