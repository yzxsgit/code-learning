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
    cin >> n;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> lc(n, -1), rc(n, -1);
    vector<int> stk;

    for (int i = 0; i < n; i++)
    {
        int last = -1;
        while (!stk.empty() && a[stk.back()] < a[i])
        {
            last = stk.back();
            stk.pop_back();
        }

        if (last != -1)
            lc[i] = last;

        if (stk.size())
            rc[stk.back()] = i;
        stk.push_back(i);
    }

    int root = stk[0];

    vector<int> sz(n, 0);
    vector<i64> f(n);
    stack<pair<int, bool>> s;
    s.push({root, false});

    while (!s.empty())
    {
        auto [v, st] = s.top();
        s.pop();
        if (st)
        {
            int ls = (lc[v] == -1) ? 0 : sz[lc[v]];
            int rs = (rc[v] == -1) ? 0 : sz[rc[v]];

            i64 lf = (lc[v] == -1) ? 0 : f[lc[v]];
            i64 rf = (rc[v] == -1) ? 0 : f[rc[v]];
            
            sz[v] = 1 + ls + rs;
            f[v] = min((i64)rf + ls, (i64)lf + rs);
        }
        else
        {
            s.push({v, true});
            if (rc[v] != -1)
                s.push({rc[v], false});
            if (lc[v] != -1)
                s.push({lc[v], false});
        }
    }

    cout << f[root] << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}