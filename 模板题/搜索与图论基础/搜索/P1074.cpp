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
using PII = pair<int,int>;

vector<vector<bool>> row(10, vector<bool>(10, false)), col(10, vector<bool>(10, false)), cude(10, vector<bool>(10, false));

vector<vector<int>> g(10, vector<int>(10, 0));

void PUT(int num, int x, int y, bool in)
{
    row[x][num] = in;
    col[y][num] = in;
    int tmp = x / 3 * 3 + y / 3;
    cude[tmp][num] = in;
    g[x][y] = num;
}

int sum()
{
    int ans = 0;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            int tmp = min({i, j, 10 - i, 10 - j}) + 5;
            ans += tmp * g[i][j];
        }

    return ans;
}

int res = -1;
PII idx[100];
void dfs(int u)
{
    if (u == 82)
    {
        res = max(res, sum());
        return;
    }
    int x = idx[u].first;
    int y = idx[u].second;

    if (g[x][y] == 0)
        for (int i = 1; i <= 9; i++)
        {
            if (row[x][i] || col[y][i] || cude[x / 3 * 3 + y / 3][i])
                continue;
            PUT(i, x, y, true);
            dfs(u + 1);
            PUT(0, x, y, false);
        }
    else
        dfs(u + 1);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int tmp = 1;
    for (int i = 1; i <= 9; i++)
        for (int j = 1; j <= 9; j++)
        {
            int x;
            cin >> x;
            PUT(x, i, j, true);
            idx[tmp] = {i, j};
        }

    cout << res << '\n';

    return 0;
}