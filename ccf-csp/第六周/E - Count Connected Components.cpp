#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;
bool g[N][N];
bool flag[N];
int q[N];
int n, m;
void bfs(int x)
{
    int head = 0,tail = 0;
    q[tail++] = x;
    flag[x] = true;
    while (head < tail)
    {
        int t = q[head++];
        for (int i = 1; i <= n; i++)
            if(!flag[i] && g[t][i])
            {
                flag[i] = true;
                q[tail++] = i;
            }
    }
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        g[x][y] = g[y][x] = 1;
    }
    int ans = 0;
    for (int i = 1; i <= n; i++)
        if(!flag[i])
        {
            ans++;
            bfs(i);
        }

    printf("%d\n", ans);

    return 0;
}