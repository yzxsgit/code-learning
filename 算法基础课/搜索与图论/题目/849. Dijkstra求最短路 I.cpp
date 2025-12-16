#include <bits/stdc++.h>
using namespace std;
const int N = 510;
int g[N][N],dist[N];
bool st[N];
int n, m;
int dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;
    
    for (int i = 0; i < n - 1; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        if (t == n)
            break;
        for (int j = 1; j <= n; j++)
            dist[j] = min(dist[j], dist[t] + g[t][j]);
        st[t] = true;
    }
    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}
int main()
{
    memset(g, 0x3f, sizeof g);
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        g[a][b] = min(g[a][b], c);
    }
    
    int ans = dijkstra();
    printf("%d", ans);

    return 0;
}