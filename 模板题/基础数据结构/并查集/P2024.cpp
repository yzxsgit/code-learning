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

    vector<int> p(n + 1), depth(n + 1, 0);
    for (int i = 1; i <= n; i++)
        p[i] = i;

    function<int(int)> find = [&](int x)
    {
        if (x != p[x])
        {
            int t = find(p[x]);
            depth[x] += depth[p[x]];
            p[x] = t;
        }
        return p[x];
    };

    int res = 0;
    while (m--)
    {
        int op, a, b;
        cin >> op >> a >> b;
        if (a > n || b > n || a == 0 || b == 0)
        {
            res++;
        }
        else
        {
            int pa = find(a), pb = find(b);
            if (op == 1)
            {
                if (pa == pb && (depth[a] - depth[b]) % 3)
                    res++;
                else if (pa != pb)
                {
                    depth[pa] = depth[b] - depth[a];
                    p[pa] = pb;
                }
            }
            else
            {
                if (pa == pb && (depth[a] - depth[b] - 1) % 3)
                    res++;
                else if (pa != pb)
                {
                    depth[pa] = 1 + depth[b] - depth[a];
                    p[pa] = pb;
                }
            }
        }
    }

    cout << res << '\n';

    return 0;
}