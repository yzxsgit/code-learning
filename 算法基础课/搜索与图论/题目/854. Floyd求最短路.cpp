#include <bits/stdc++.h>
using namespace std;
const int N = 210;
int dist[N][N];
int n, m, Q;

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
    scanf("%d%d%d", &n, &m, &Q);
    
    memset(dist, 0x3f, sizeof dist);
    for (int i = 1; i <= n; i++)
        dist[i][i] = 0;
    while (m--)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        dist[a][b] = min(dist[a][b], w);
    }

    floyd();

    while (Q--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        if (dist[a][b] < 0x3f3f3f3f / 2)
            printf("%d\n", dist[a][b]);
        else
            printf("impossible\n");
    }

    return 0;
}