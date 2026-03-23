#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

vector<vector<int>> dist;
int n, m;

void bfs(int x, int y)
{
    int dx[] = {-1, -2, -2, -1, 1, 2, 2, 1};
    int dy[] = {-2, -1, 1, 2, -2, -1, 1, 2};
    queue<PII> q;
    dist[x][y] = 0;
    q.push({x, y});

    while (q.size())
    {
        x = q.front().first;
        y = q.front().second;
        q.pop();

        for (int i = 0; i < 8; i++)
        {
            int nx = x + dx[i], ny = y + dy[i];
            if (nx <= 0 || nx > n || ny <= 0 ||ny > m)
                continue;
            if (dist[nx][ny] == -1)
            {
                dist[nx][ny] = dist[x][y] + 1;
                q.push({nx, ny});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int x, y;
    cin >> n >> m >> x >> y;

    dist.resize(n + 1, vector<int>(m + 1, -1));

    bfs(x, y);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cout << dist[i][j] << (j == m ? '\n' : ' ');

    return 0;
}