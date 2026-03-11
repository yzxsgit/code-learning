#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <functional>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<int> a(m), b(m), parity(m);
    vector<int> coords;

    string str;

    for (int i = 0; i < m; i++)
    {
        cin >> a[i] >> b[i] >> str;
        a[i]--;

        coords.push_back(a[i]);
        coords.push_back(b[i]);
        parity[i] = (str == "odd" ? 1 : 0);
    }

    sort(coords.begin(), coords.end());
    coords.erase(unique(coords.begin(), coords.end()), coords.end());

    int sz = coords.size();

    vector<int> p(sz), rel(sz, 0);

    for (int i = 0; i < sz; i++)
    {
        p[i] = i;
    }

    function<int(int)> find = [&](int x)
    {
        if (p[x] != x)
        {
            int root = find(p[x]);
            rel[x] ^= rel[p[x]];
            p[x] = root;
        }
        return p[x];
    };

    auto to_idx = [&](int x)
    {
        return lower_bound(coords.begin(), coords.end(), x) - coords.begin();
    };

    for (int i = 0; i < m; i++)
    {
        int u = to_idx(a[i]);
        int v = to_idx(b[i]);
        int pu = find(u), pv = find(v);
        if (pu == pv)
        {
            if ((rel[v] ^ rel[u]) != parity[i])
            {
                cout << i << '\n';
                return 0;
            }
        }
        else
        {
            p[pv] = pu;
            rel[pv] = rel[u] ^ rel[v] ^ parity[i];
        }
    }

    cout << m << '\n';

    return 0;
}