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

vector<PII> g;
int ans = 0;

PII dfs(int u, int d)
{
    if (u == -1)
    {
        return {d, d};
    }

    PII L = dfs(g[u].first, d + 1);
    PII R = dfs(g[u].second, d + 1);

    int cur_min = min(L.first, R.first);
    int cur_max = max(L.second, R.second);
    if (cur_max - cur_min > 1)
    {
        cout << -1 << '\n';
        exit(0);
    }

    if (L.first != L.second && R.first != R.second)
    {
        cout << -1 << '\n';
        exit(0);
    }

    if (L.first < R.first || L.second < R.second)
    {
        ans++;
    }

    return {cur_min, cur_max};
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    g.resize(n + 1);

    for (int i = 1; i <= n; i++)
    {
        int a, b;
        cin >> a >> b;
        g[i] = {a, b};
    }

    dfs(1, 1);

    cout << ans << '\n';

    return 0;
}