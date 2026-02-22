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
    int n;
    cin >> n;
    vector<vector<i64>> s(3, vector<i64>(n + 1));

    for (int i = 0; i < 3; i++)
        for (int j = 1; j <= n; j++)
        {
            cin >> s[i][j];
            s[i][j] += s[i][j - 1];
        }
    i64 need = (s[0][n] + 2) / 3; 
    vector<tuple<int,int,int>> perm = {{0,1,2}, {0,2,1}, {1,0,2}, {1,2,0}, {2,0,1}, {2,1,0}};

    vector<PII> res(3);

    for (auto [x, y, z] : perm)
    {
        int p1 = 1;
        while (p1 <= n && s[x][p1] < need)
            p1++;
        if (p1 > n)
            continue;

        int p2 = p1 + 1;
        while (p2 <= n && s[y][p2] - s[y][p1]< need)
            p2++;
        if (p2 > n)
            continue;

        if (s[z][n] - s[z][p2] >= need)
        {
            res[x] = {1, p1};
            res[y] = {p1 + 1, p2};
            res[z] = {p2 + 1, n};
            for (int i = 0; i < 3; i++)
                cout << res[i].first << ' ' << res[i].second << ' ';
            cout << '\n';
            return;
        }
    }
    cout << -1 << '\n';
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