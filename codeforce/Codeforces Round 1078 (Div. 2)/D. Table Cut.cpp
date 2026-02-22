#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;


void solve()
{
    int n, m;
    cin >> n >> m;
    vector<vector<bool>> g(n, vector<bool>(m, 0)), st(n, vector<bool>(m, 0));

    int total = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            g[i][j] = x;
            total += x;
        }

    int target = total / 2;
    queue<PII> q;
    q.push({0, m - 1});
    st[0][m - 1] = true;
    target -= g[0][m - 1];
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        int x = t.first, y = t.second;
        int dx = x , dy = y - 1;
        if (dx >= 0 && dx < n && dy >= 0 && dy < m && !st[dx][dy] && target > 0)
        {
            target -= g[dx][dy];
            q.push({dx, dy});
            st[dx][dy] = true;
        }
        dx = x + 1, dy = y;
        if (dx >= 0 && dx < n && dy >= 0 && dy < m && !st[dx][dy] && target > 0)
        {
            target -= g[dx][dy];
            q.push({dx, dy});
            st[dx][dy] = true;
        }
        if (target == 0)
            break;
    }

    cout << (total / 2) * (total - total / 2) << '\n';
    int dx[] = {0, 1}, dy[] = {1, 0};
    int x = 0, y = 0;
    for (int i = 0; i < n + m; i++)
    {
        if (x == n)
        {
            cout << 'R';
            continue;
        }
        if (y == m)
        {
            cout << 'D';
            continue;
        }
        int v = st[x][y];
        if (st[x][y])
            cout << 'D';
        else
            cout << 'R';
        x += dx[v];
        y += dy[v];
    }
    cout << '\n';

    
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