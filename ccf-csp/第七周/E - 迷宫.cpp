#include <iostream>

using namespace std;
const int N = 10, dx[4] = {0, -1, 0, 1}, dy[4] = {1, 0, -1, 0};
bool ob[N][N];
int sx, sy, fx, fy;
int ans;
int n, m;
void dfs(int x,int y)
{
    if(x == fx && y == fy)
    {
        ans++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 1 && nx <= n && ny >= 1 && ny <= m && !ob[nx][ny])
        {
            ob[nx][ny] = true;
            dfs(nx,ny);
            ob[nx][ny] = false;
        }
    }
}
int main()
{
    int t;
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        ob[a][b] = true;
    }

    ob[sx][sy] = true;
    dfs(sx, sy);

    printf("%d\n", ans);

    return 0;
}