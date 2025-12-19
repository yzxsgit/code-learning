#include <iostream>
#include <cstring>

using namespace std;
const int N = 15,
          dx[] = {-1, -1, 1, 1, -2, -2, 2, 2},
          dy[] = {-2, 2, -2, 2, -1, 1, -1, 1};

bool st[N][N];
int n, m;
int ans = 0;

void dfs(int x, int y, int cnt)
{
    if (cnt == n * m)
    {
        ans++;
        return;
    }

    st[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 0 || a >= n || b < 0 || b >= m) 
            continue;
        if (st[a][b])
            continue;

        dfs(a, b, cnt + 1);
    }
    st[x][y] = false;

}

void solve()
{
    memset(st, 0, sizeof st);

    int x, y;
    cin >> n >> m >> x >> y;

    ans = 0;
    dfs(x, y, 1);
    cout << ans << "\n";

    return;
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