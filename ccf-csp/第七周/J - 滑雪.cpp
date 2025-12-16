#include <iostream>
#include <cstring>

using namespace std;
const int N = 110, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int h[N][N], f[N][N];
int n, m;
int dp(int x,int y)
{
    int &v = f[x][y];
    if (v != -1)
        return v;

    v = 1;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx < n && ny >= 0 && ny < m && h[nx][ny] > h[x][y])
            v = max(v, dp(nx, ny) + 1);
    }

    return v;
}

int main()
{
    memset(f, -1, sizeof f);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            scanf("%d", &h[i][j]);

    int res = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            res = max(res, dp(i, j));

    cout << res << endl;

    return 0;
}