#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int N = 110, INF = 0x3f3f3f3f;
int a[N][N], b[N][N];
int n, m, d;
bool visited[N];
int dist[N];
int bfs(int x, int y)
{
    memset(dist, 0x3f, sizeof dist);
    dist[x] = 0;
    for (int i = 1; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if(!visited[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        if (t == y)
            break;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + b[t][j]);
        // printf("%d\n", t);
        visited[t] = true;
    }

    return dist[y];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if(i == j)
                a[i][j] = 0;
            else
                a[i][j] = INF;

    for (int i = 1; i <= m; i++)
    {
        int x, y, w;
        scanf("%d%d%d", &x, &y, &w);
        a[x][y] = min(w, a[x][y]);
        a[y][x] = min(w, a[y][x]);
    }
    scanf("%d", &d);
    while (d--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        b[x][y] = a[x][y];
        b[y][x] = a[y][x];
    }

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if(a[i][j] == INF)
                b[i][j] = INF;

    // for (int i = 1; i <= n; i++)
    // {    
    //     for (int j = 1; j <= n; j++)
    //     {
    //         printf("%d ",b[i][j]);
    //     }
    //     printf("\n");
    // }
    int start, end;
    scanf("%d%d", &start, &end);

    int res = bfs(start, end);

    printf("%d\n", res);

    return 0;
}