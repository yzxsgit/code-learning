#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int N = 1010, dx[] = {0, 1, 0, -1}, dy[] = {1, 0, -1, 0};
typedef pair<int, int> PII;

int n;
bool g[N][N];
PII pre[N][N];
bool st[N][N];

void bfs(int sx,int sy)
{
    queue<PII> q;
    q.push({sx, sy});
    st[sx][sy] = true;

    while (q.size())
    {
        PII t = q.front();
        q.pop();
        int x = t.first, y = t.second;

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= n)
                continue;
            if (g[nx][ny])
                continue;
            if (st[nx][ny]) 
                continue;
            
            st[nx][ny] = true;
            pre[nx][ny] = {x, y};
            q.push({nx, ny});
        }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    bfs(n - 1, n - 1);

    PII end(0, 0);

    while (true)
    {
        printf("%d %d\n", end.first, end.second);
        if (end.first == n - 1 && end.second == n - 1)
            break;
        end = pre[end.first][end.second];   
    }

    return 0;
}