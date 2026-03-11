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
using PII = pair<int,int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    int n = 3e4;
    vector<int> p(n + 1), d(n + 1, 0), s(n + 1, 1);
    for (int i = 1; i <= n; i++)
        p[i] = i;

    function<int(int)> find = [&](int x)
    {
        if (p[x] != x)
        {
            int y = find(p[x]);
            d[x] += d[p[x]];
            p[x] = y;
        }
        return p[x];
    };

    while (t--)
    {
        char op[2];
        int a, b;
        cin >> op >> a >> b;

        if (op[0] == 'M')
        {
            int pa = find(a), pb = find(b);

            if (pa != pb)
            {
                d[pa] = s[pb];
                s[pb] += s[pa];
                p[pa] = pb;
            }
        }
        else
        {
            int pa = find(a), pb = find(b);
            cout << (pa == pb ? max(0, abs(d[a] - d[b]) - 1) : -1) << '\n';
        }
    }

    return 0;
}