#include <iostream>
#include <queue>
using namespace std;
const int N = 1010, dx[4] = {0, 1, 0, -1}, dy[4] = {1, 0, -1, 0};
char a[N][N];
int b[N][N];
bool f[N][N];
int n, m;

void bfs()
{
    queue<pair<int, int>> q;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(a[i][j] == '1')
            {
                f[i][j] = true;
                q.push({i, j});
            }
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nx = t.first + dx[i], ny = t.second + dy[i];
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !f[nx][ny])
            {
                b[nx][ny] = b[t.first][t.second] + 1;
                f[nx][ny] = true;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", a[i]);

    bfs();

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            printf("%d ", b[i][j]);
        puts("");
    }

    return 0;
}