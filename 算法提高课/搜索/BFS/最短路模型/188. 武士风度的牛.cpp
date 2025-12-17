#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int N = 160,
          dx[] = {-2, -1, 1, 2, 2, 1, -1, -2},
          dy[] = {1, 2, 2, 1, -1, -2, -2, -1};
typedef pair<int, int> PII;

int n, m;
char g[N][N];
int dist[N][N];

int bfs()
{
    int sx, sy;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if (g[i][j] == 'K')
                sx = i, sy = j;
    queue<PII> q;
    q.push({sx, sy});
    dist[sx][sy] = 0;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        int x = t.first, y = t.second;
        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;    
            if (g[nx][ny] == '*')
                continue;
            if (dist[nx][ny] != -1)
                continue;
            if (g[nx][ny] == 'H')
                return dist[x][y] + 1;

            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx, ny});
        }
    }

    return -1;
}

int main()
{
    memset(dist, -1, sizeof dist);
    
    cin >> m >> n;

    for (int i = 0; i < n; i++)
        cin >> g[i];

    cout << bfs() << "\n";

    return 0;
}