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

vector<vector<int>> g;
vector<int> color;

int cnt[3];

bool flag;

void dfs(int u, int c)
{
    color[u] = c;
    cnt[c]++;
    for (int v : g[u])
    {
        if (!color[v])
        {
            dfs(v, 3 - c);
        }
        else if (color[v] == c)
        {
            flag = false;
        }
    }
}

void solve()
{
    g.clear();
    color.clear();

    int n, m;
    cin >> n >> m;

    g.resize(n + 1);
    color.assign(n + 1, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!color[i])
        {
            flag = true;
            cnt[1] = cnt[2] = 0;
            dfs(i, 1);
            if (flag)
            {
                res += max(cnt[1], cnt[2]);
            }
        }
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
    }
    return 0;
}