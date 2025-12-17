#include <iostream>
#include <queue>

using namespace std;
const int N = 1010;
typedef pair<int, int> PII;

int g[N][N];
bool st[N][N];
int n;

void bfs(int sx, int sy, bool &has_higher, bool &has_lower)
{
    queue<PII> q;
    q.push({sx, sy});
    st[sx][sy] = true;

    while (q.size())
    {
        PII t = q.front();
        q.pop();
        int x = t.first, y = t.second;

        for (int i = x - 1; i <= x + 1; i++)
            for (int j = y - 1; j <= y + 1; j++)
            {
                if(i == x && j == y)
                    continue;
                if (i < 0 || i >= n || j < 0 || j >= n)
                    continue;
                if (g[i][j] < g[sx][sy])
                    has_lower = true;
                else if (g[i][j] > g[sx][sy])
                    has_higher = true;
                else if (!st[i][j])
                {
                    st[i][j] = true;
                    q.push({i, j});
                }
            }
    }
}

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &g[i][j]);

    int valley = 0, peak = 0;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if(!st[i][j])
            {
                bool has_higher = false, has_lower = false;
                bfs(i, j, has_higher, has_lower);
                if (!has_higher)
                    peak++;
                if (!has_lower)
                    valley++;
            }

    printf("%d %d\n", peak, valley);

    return 0;
}