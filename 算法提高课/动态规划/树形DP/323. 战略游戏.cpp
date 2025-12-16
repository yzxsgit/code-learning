#include <iostream>
#include <cstring>

using namespace std;

const int N = 1510;

int h[N], e[N], ne[N], idx;
bool st[N];
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int f[N][2];

void dfs(int u)
{
    f[u][0] = 0;
    f[u][1] = 1;

    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];

        dfs(j);

        f[u][0] += f[j][1];
        f[u][1] += min(f[j][1], f[j][0]);
    }
}

void solve(int n)
{
    memset(h, -1, sizeof h);
    idx = 0;
    memset(st, 0, sizeof st);

    for (int i = 0; i < n; i++)
    { 
        int id, ver, num;
        scanf("%d:(%d) ", &id, &num);

        for (int i = 0; i < num; i++)
        {
            scanf("%d", &ver);
            st[ver] = true;
            add(id, ver);
        }
    }

    int root = 0;
    while (st[root])
        root++;

    dfs(root);

    printf("%d\n", min(f[root][1], f[root][0]));
}

int main()
{
    int t;
    while (~scanf("%d",&t))
        solve(t);

    return 0;
}