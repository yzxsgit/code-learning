#include <iostream>
#include <cstring>

using namespace std;
const int N = 25,
          dx[] = {0, 1, 0, -1},
          dy[] = {1, 0, -1, 0};

char g[N][N];
int n, m;
bool st[N][N];

int dfs(int x, int y)
{
    st[x][y] = true;
    int cnt = 1;

    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];

        if (a < 0 || a >= n || b < 0 || b >= m)
            continue;
        if (g[a][b] != '.')
            continue;
        if (st[a][b])
            continue;

        cnt += dfs(a, b);
    }

    return cnt;
}

void solve()
{
    memset(st, 0, sizeof st);

    for (int i = 0; i < n; i++)
        cin >> g[i];
    int x, y;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == '@')
                x = i, y = j;

    cout << dfs(x, y) << "\n";
}

int main()
{
    while (cin >> m >> n, m || n)
    {
        solve();
    }

    return 0;
}