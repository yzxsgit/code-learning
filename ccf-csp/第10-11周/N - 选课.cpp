#include <iostream>
#include <cstring>

using namespace std;
const int N = 310;
int f[N][N], w[N];
int n, m;
int h[N], ne[N], e[N], idx;
void add(int a,int b)
{
    e[++idx] = b, ne[idx] = h[a], h[a] = idx;
}

void dfs(int u,int tot)
{
    if(tot <= 0)
        return;
    for (int i = h[u]; i; i = ne[i])
    {
        int j = e[i];
        for (int k = 0; k < tot; k++)
            f[j][k] += f[u][k] + w[j];
        dfs(j, tot - 1);
        for (int k = 1; k <= tot; k++)
            f[u][k] = max(f[u][k], f[j][k - 1]);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a >> w[i];
        add(a, i);
    }

    dfs(0, m);

    cout << f[0][m] << endl;

    return 0;
}