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

int res = 0;
vector<int> ans;

vector<bool> row, col, dg, udg;

int n;

void dfs(int u)
{
    if (u == n + 1)
    {
        res++;
        if (res <= 3)
        {
            for (int i = 1; i <= n; i++)
                cout << ans[i] << ' ';
            cout << '\n';
        }
        return;
    }

    for (int i = 1; i <= n; i++)
        if (!col[i] && !dg[u + n - i] && !udg[u + i])
        {
            ans[u] = i;
            col[i] = dg[u + n - i] = udg[u + i] = true;
            dfs(u + 1);
            col[i] = dg[u + n - i] = udg[u + i] = false;
        }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    row.resize(n + 1), col.resize(n + 1);
    dg.resize(2 * n + 1), udg.resize(2 * n + 1);
    ans.resize(n + 1);

    dfs(1);

    cout << res << '\n';

    return 0;
}