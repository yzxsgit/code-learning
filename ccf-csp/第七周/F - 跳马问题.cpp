#include <iostream>

using namespace std;

const int N = 20, dx[4] = {2, 1, 2, 1}, dy[4] = {1, 2, -1, -2};

bool f[N][N];
int total;
int n, m;

void dfs(int x,int y)
{
    if (x == n && y == m)
    {
        total++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx <= n && ny <= m && ny >= 0 && !f[nx][ny])
        {
            f[nx][ny] = true;
            dfs(nx, ny);
            f[nx][ny] = false;
        }
    }
}

int main()
{
    cin >> m >> n;

    f[0][0] = true;
    dfs(0, 0);

    cout << total;

    return 0;
}