#include <iostream>
#include <cstring>

using namespace std;
const int N = 110,
          dx[] = {-1, 0, 1, 0},
          dy[] = {0, 1, 0, -1};
char g[N][N];
bool st[N][N];
int xa, ya, xb, yb;
int n;

bool dfs(int x, int y)
{
    if (g[x][y] == '#')
        return false;
    if (x == xb && y == yb)
        return true;
    st[x][y] = true;

    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= n)
            continue;
        if (st[a][b])
            continue;
        if (dfs(a, b))
            return true;
    }
    return false;
}

void solve()
{
    memset(st, 0, sizeof st);
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> g[i];

    cin >> xa >> ya >> xb >> yb;

    cout << (dfs(xa, ya) ? "YES" : "NO") << "\n";
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}