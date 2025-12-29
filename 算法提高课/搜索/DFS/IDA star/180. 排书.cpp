#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int n;
int q[15];
int back_up[5][15];

int f()
{
    int total = 0;
    for (int i = 0; i < n - 1; i++)
    {
        if (q[i + 1] != q[i] + 1)
            total++;
    }
    return (total + 2) / 3;
}

bool dfs(int depth, int max_depth)
{
    int h = f();
    if (depth + h > max_depth)
        return false;
    if (h == 0)
        return true;

    for (int len = 1; len < n; len++)
    {
        for (int l = 0; l <= n - len; l++)
        {
            int r = l + len - 1;
            for (int k = r + 1; k < n; k++)
            {
                for (int i = 0; i < n; i++)
                    back_up[depth][i] = q[i];

                int y = l;
                for (int x = r + 1; x <= k; x++, y++)
                    q[y] = back_up[depth][x];
                for (int x = l; x <= r; x++, y++)
                    q[y] = back_up[depth][x];

                if (dfs(depth + 1, max_depth))
                    return true;
                for (int i = 0; i < n; i++)
                    q[i] = back_up[depth][i];
            }
        }
    }
    return false;
}

void solve()
{
    if (!(cin >> n))
        return;
    for (int i = 0; i < n; i++)
        cin >> q[i];

    int depth = 0;
    while (depth < 5 && !dfs(0, depth))
        depth++;

    if (depth >= 5)
        cout << "5 or more" << endl;
    else
        cout << depth << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--)
        solve();
    return 0;
}