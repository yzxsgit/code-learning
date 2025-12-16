#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;

const int N = 110;

int n, m;
int d[N][N];
bool st[N][N];

int bfs()
{
    int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
    queue<PII> q;
    memset(d, -1, sizeof(d));
    d[0][0] = 0;
    q.push({0, 0});
    while (q.size())
    {
        PII t = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int x = t.first + dx[i], y = t.second + dy[i];
            if (x >= 0 && x < n && y >= 0 && y < m && st[x][y] == 0 && d[x][y] == -1)
            {
                d[x][y] = d[t.first][t.second] + 1;
                q.push({x, y});
            }
        }
    }

    return d[n - 1][m - 1];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> st[i][j];

    printf("%d", bfs());

    return 0;
}