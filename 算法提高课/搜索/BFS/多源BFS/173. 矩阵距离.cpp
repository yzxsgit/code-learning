#include <iostream>
#include <queue>

using namespace std;
const int N = 1010,
          dx[] = {-1, 0, 1, 0},
          dy[] = {0, 1, 0, -1};

int dist[N][N];
char g[N][N];
int n, m;
bool st[N][N];

void bfs()
{
    queue<pair<int, int>> q;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (g[i][j] == '1')
            {
                st[i][j] = true;
                q.push({i, j});
            }

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        int x = t.first, y = t.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || nx > n || ny <= 0 || ny > m)
                continue;
            if (st[nx][ny])
                continue;
            st[nx][ny] = true;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }
}

int main()
{

    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        cin.ignore();
        for (int j = 1; j <= m; j++)
            g[i][j] = getchar();
        
    }

    bfs();

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
            printf("%d ", dist[i][j]);
        printf("\n");
    }

    return 0;
}