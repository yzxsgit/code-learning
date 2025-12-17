#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 1010;
typedef pair<int, int> PII;

char g[N][N];
bool st[N][N];
int n, m;
int cnt;

void bfs(int sx,int sy)
{
    queue<PII> q;
    q.push({sx, sy});
    st[sx][sy] = true;

    while (q.size())
    {
        PII t = q.front();
        q.pop();

        int nx = t.first, ny = t.second;
        for (int i = nx - 1; i <= nx + 1; i++)
            for (int j = ny - 1; j <= ny + 1; j++)
            {
                if (i < 0 || i >= n || j < 0 || j >= m)
                    continue;
                if (i == nx && j == ny)
                    continue;
                if (g[i][j] == '.')
                    continue;
                if (st[i][j])
                    continue;
                st[i][j] = true;
                q.push({i, j});
            }
    }
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%s", g[i]);

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if(g[i][j] == 'W' && !st[i][j])
            {
                bfs(i, j);
                cnt++;
            }

    printf("%d\n", cnt);

    return 0;
}