#include <bits/stdc++.h>
using namespace std;

const int N = 6e3 + 10;
int h[N], e[N], ne[N], idx;
int H[N];
int f[N][2];
int n;
bool has_father[N];

void add(int x,int y)
{
    e[idx] = x, ne[idx] = h[y], h[y] = idx++;
}

void dfs(int u)
{
    f[u][1] = H[u];

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];

        dfs(j);

        f[u][0] += max(f[j][0], f[j][1]);
        f[u][1] += f[j][0];
    }
}

int main()
{

    memset(h, -1, sizeof h);
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &H[i]);

    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d %d", &a, &b);
        add(a, b);
        has_father[a] = true;
    }

    int root = 1;
    while(has_father[root])
        root++;

    dfs(root);

    printf("%d", max(f[root][1], f[root][0]));

    return 0;
}