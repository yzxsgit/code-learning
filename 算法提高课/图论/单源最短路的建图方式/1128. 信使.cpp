#include <iostream>
#include <cstring>

using namespace std;
const int N = 110, INF = 0x3f3f3f3f;

int dist[N][N];
int n, m;

void floyd()
{            
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
}

int main()
{
    memset(dist, 0x3f, sizeof dist);

    cin >> n >> m;
    for (int i = 1; i <= n; i ++ ) dist[i][i] = 0;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        dist[a][b] = dist[b][a] = min(dist[a][b], c);
    }

    floyd();

    int res = 0;
    for (int i = 1; i <= n; i++)
    {
        if(dist[1][i] == INF)
        {
            res = -1;
            break;
        }
        else
            res = max(dist[1][i], res);
    }

    cout << res << "\n";

    return 0;
}