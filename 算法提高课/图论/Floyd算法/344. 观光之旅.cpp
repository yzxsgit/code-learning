#include <iostream>
#include <cstring>

using namespace std;

const int N = 110;

int g[N][N], d[N][N];
int n, m;
int pos[N][N];
int path[N], cnt;
int res = 0x3f3f3f3f;

void get_path(int i, int j)
{
    if (pos[i][j] == 0)
        return;

    int k = pos[i][j];
    get_path(i, k);
    path[cnt++] = k;
    get_path(k, j);
}

void floyd()
{
    memcpy(d, g, sizeof d);
    for (int k = 1; k <= n; k++)
    {
        for (int i = 1; i < k; i++)
            for (int j = i + 1; j < k; j++)
                if ((long long)d[i][j] + g[j][k] + g[k][i] < res)
                {
                    res = d[i][j] + g[j][k] + g[k][i];
                    cnt = 0;
                    path[cnt++] = k;
                    path[cnt++] = i;
                    get_path(i, j);
                    path[cnt++] = j;
                }

        for (int i = 1; i < n; i++)
            for (int j = 1; j < n; j++)
                if (d[i][k] + d[k][j] < d[i][j])
                {
                    d[i][j] = d[i][k] + d[k][j];
                    pos[i][j] = k;
                }
    }
}

int main()
{
    cin >> n >> m;

    memset(g, 0x3f, sizeof g);

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;

        g[a][b] = g[b][a] = min(g[a][b], c);
    }

    floyd();

    if (res == 0x3f3f3f3f)
        puts("No solution.");
    else
        for (int i = 0; i < cnt; i++)
            cout << path[i] << " ";

    return 0;
}