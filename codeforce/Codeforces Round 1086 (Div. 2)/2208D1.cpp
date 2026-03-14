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

void solve()
{
    int n;
    cin >> n;
    cin.ignore();
    vector<vector<bool>> g(n + 1, vector<bool>(n + 1, false)), mp(n + 1, vector<bool>(n + 1, false));

    for (int i = 1; i <= n; i++)
    {
        string ch;
        cin >> ch;
        for (int j = 0; j < n; j++)
        {
            g[i][j + 1] = ch[j] - '0';
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            mp[i][j] = g[j][i] || g[i][j];
    }

    int root = 0;
    for (int i = 1; i <= n; i++)
    {
        bool flag = true;
        for (int j = 1; j <= n; j++)
        {
            if (!mp[i][j])
                flag = false;
        }

        if (flag)
        {
            if (!root)
            {
                root = i;
            }
            else
            {
                cout << "NO\n";
                return;
            }
        }
    }

    cout << "YES\n";

    queue<int> q;
    vector<bool> visited(n + 1, 0);
    visited[root] = true;
    int tmp = 1;
    for (int j = 1; j <= n; j++)
    {
        if (j != root && g[root][j])
        {
            cout << root << ' ' << j << '\n';
            tmp++;
            visited[j] = true;
            q.push(j);
        }
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();

        for (int i = 1; i <= n; i++)
        {
            if (!visited[i] && g[t][i])
            {
                cout << t << ' ' << i << '\n';
                visited[i] = true;
                q.push(i);
            }
        }
    }
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