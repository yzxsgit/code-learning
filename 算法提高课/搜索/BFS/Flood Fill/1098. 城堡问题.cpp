#include <iostream>
#include <queue>

using namespace std;
const int N = 60, dx[4] = {0, -1, 0, 1}, dy[4] = {-1, 0, 1, 0};
typedef pair<int, int> PII;

int g[N][N];
int n, m;
bool st[N][N];

int bfs(int sx,int sy)
{
    queue<PII> q;
    q.push({sx, sy});
    st[sx][sy] = true;
    int area = 0;
    
    while (q.size())
    {
        PII t = q.front();
        q.pop();
        area++;

        int x = t.first, y = t.second;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                continue;
            if (g[x][y] >> i & 1)
                continue;
            if (st[nx][ny])
                continue;
            st[nx][ny] = true;
            q.push({nx, ny});
        }
    }

    return area;
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> g[i][j];

    int max_room = 0, room_count = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(!st[i][j])
            {
                max_room = max(max_room, bfs(i, j));
                room_count++;
            }

    cout << room_count << "\n";
    cout << max_room << "\n";

    return 0;
}