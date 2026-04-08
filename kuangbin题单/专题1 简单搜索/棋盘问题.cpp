#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

const int N = 10;

char g[N][N];
int n, k;
bool col[N];
int res = 0;

void dfs(int m, int line)
{
    if (m == 0)
    {
        res++;
        return;
    }

    if (line >= n || n - line < m)
        return;

    for (int i = 0; i < n; i++)
        if (g[line][i] == '#' && !col[i])
        {
            col[i] = true;
            dfs(m - 1, line + 1);
            col[i] = false;
        }

    dfs(m, line + 1);
}

void solve()
{
    res = 0;
    memset(col, false, sizeof col); 

    for (int i = 0; i < n; i++)
        cin >> g[i];

    dfs(k, 0);

    cout << res << '\n';
}

int main()
{
    while (cin >> n >> k && n != -1 && k != -1)
    {
        solve();
    }

    return 0;
}