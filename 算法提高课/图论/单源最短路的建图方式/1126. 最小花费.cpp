#include <iostream>
#include <cstring>

using namespace std;
const int N = 2010;

int n, m, S, T;
double g[N][N];
double dist[N];
bool st[N];

void dijkstra()
{

    dist[S] = 1;

    for (int i = 1; i <= n; i++)
    {
        int t = -1;
        for (int j = 1; j <= n; j++)
            if(!st[j] && (t == -1 || dist[j] > dist[t]))
                t = j;
        st[t] = true;

        for (int j = 1; j <= n; j++)
            dist[j] = max(dist[j], dist[t] * g[t][j]);
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        double z = (100.0 - c) / 100;
        g[a][b] = g[b][a] = z;
    }

    scanf("%d%d", &S, &T);

    dijkstra();

    printf("%.8lf", 100 / dist[T]);

    return 0;
}