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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m;

    cin >> n >> m;

    vector<vector<int>> g(n + 1, vector<int>(m + 2, 0));

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
        {
            char ch[2];
            cin >> ch;
            if (ch[0] == 'F')
            {
                g[i][j] = g[i - 1][j] + 1;
            }
        }

    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        stack<int> stk;

        for (int j = 1; j <= m + 1; j++)
        {
            while (stk.size() && g[i][j] < g[i][stk.top()])
            {
                int h = g[i][stk.top()];
                stk.pop();

                int left = stk.empty() ? 0 : stk.top();
                int width = j - left - 1;

                res = max(res, h * width);
            }

            stk.push(j);
        }
    }

    cout << res * 3 << '\n';

    return 0;
}