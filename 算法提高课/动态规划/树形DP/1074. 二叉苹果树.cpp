#include <iostream>
#include <cstring>

using namespace std;

const int N = 110, M = 2 * N;
int f[N][N];
int h[N], e[M], w[M], ne[M], idx;

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int n, m;

void dfs(int u, int father)
{
    for (int i = h[u]; ~i; i = ne[i])
    {
        int p = e[i];
        if (p == father)
            continue;

        dfs(p,u);

        for (int j = m; j >= 0; j--)
            for (int k = 0; k < j; k++)
                f[u][j] = max(f[u][j], f[u][j - k - 1] + f[p][k] + w[i]);
    }
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;
    for (int i = 1; i < n; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dfs(1, -1);

    cout << f[1][m] << "\n";

    return 0;
}