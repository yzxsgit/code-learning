#include <iostream>
#include <cstring>
using namespace std;
const int N = 110, M = 1e4 + 10;
int danger[N][N];
int a[M];
int d[N];
bool visited[N];
int n, m;
void dijsktra(int x)
{
    memset(visited, false, sizeof visited);
    memset(d, 0x3f3f3f3f, sizeof d);
    d[x] = 0;

    for (int i = 1; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if(!visited[j] && (t==-1 || d[j] < d[t]))
                t = j;
        for (int j = 1; j <= n; j++)
            d[j] = min(d[j], d[t] + danger[t][j]);
        visited[t] = true;
    }
    // for (int i = 1; i <= n;i++)
    //     printf("%d ", d[i]);
    // printf("\n");
    for (int i = 1; i <= n; i++)
        danger[x][i] = min(danger[x][i], d[i]);
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i]);

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            scanf("%d", &danger[i][j]);

    for (int i = 1; i <= n; i++)
        dijsktra(i);
    int res = 0;
    for (int i = 1; i < m; i++)
        res += danger[a[i]][a[i + 1]];
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         printf("%d ", danger[i][j]);
    //     printf("\n");
    // }
    printf("%d", res);

    return 0;
}