#include <bits/stdc++.h>
using namespace std;
const int N = 510, INF = 0x3f3f3f3f;
int n, m;
int g[N][N], dist[N];
bool st[N];
int Prim()
{
    memset(dist, 0x3f, sizeof dist);
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        
        if(i)
            res += dist[t];
        if(i && dist[t] == INF)
            return INF;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], g[t][j]);

        st[t] = true;
    }

    return res;
}
int main()
{
    memset(g, 0x3f, sizeof g);
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = g[b][a] =min(g[a][b], c);
    }

    int t;
    t = Prim();

    if(t == INF)
        printf("impossible\n");
    else
        printf("%d", t);

    return 0;
}