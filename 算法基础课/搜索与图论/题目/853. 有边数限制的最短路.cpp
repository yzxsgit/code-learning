#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 1e4 + 10;
struct Edges{
    int x, y, w;
} edges[M];
int dist[N], backup[N];
int n, m, k;
void bellman_ford()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    for (int i = 0; i < k; i ++)
    {
        memcpy(backup, dist, sizeof dist);
        for (int j = 0; j < m; j ++)
            dist[edges[j].y] = min(dist[edges[j].y], backup[edges[j].x] + edges[j].w);
    }

    return;
}

int main()
{
    scanf("%d%d%d", &n, &m, &k);
    for (int i = 0; i < m; i ++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        edges[i] = {a, b, c};
    }

    bellman_ford();

    if(dist[n] > 0x3f3f3f3f / 2)
        printf("impossible");
    else
        printf("%d", dist[n]);

    return 0;
}