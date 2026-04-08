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

struct DSU
{
    vector<int> p;
    vector<int> sz;
    DSU(int n) : p(n + 1), sz(n + 1, 1) 
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
            sz[py] += sz[px];
            return true;
        }
        return false;
    }

    bool connected(int x, int y)
    {
        return find(x) == find(y);
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;

    while (cin >> n >> m, n || m)
    {
        DSU dsu(n);
        for (int i = 0; i < m; i++)
        {
            int k;
            cin >> k;
            if (k == 0)
                continue;

            int first;
            cin >> first;
            for (int j = 1; j < k; j++)
            {
                int other;
                cin >> other;
                dsu.unite(first, other);
            }
        }
        cout << dsu.sz[dsu.find(0)] << '\n';
    }

    return 0;
}