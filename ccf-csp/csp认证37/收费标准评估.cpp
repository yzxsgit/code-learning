#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;
int w[N];
int h[N * 2], e[N * 2], ne[N * 2], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int n, m;
long long f[N];
bool visited[N];
void dfs(int x)
{
    if(!visited[x])
    {
        f[x] = w[x];
        visited[x] = true;
    }
    for (int i = h[x]; i != -1; i = ne[i])
    {
        int j = e[i];
        if(!visited[j])
        {
            dfs(j);
            f[x] += max((long long)0,f[j]);
        }
    }
}
int main()
{
    memset(h, -1, sizeof h);
    memset(f, 0, sizeof f);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);
    for (int i = 1; i < n; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    int begin = 1;
    dfs(begin);
    printf("%lld\n", f[begin]);
    while (m--)
    {
        int op, x;
        long long res = 0;
        memset(visited, 0, sizeof visited);
        scanf("%d", &op);
        if (op == 1)
        {
            scanf("%d", &x);
            res = -w[x];
            begin = x;
        }
        else if (op == 2)
        {
            int d;
            scanf("%d%d", &x, &d);
            w[x] = d;
        }
        else
        {
            scanf("%d", &x);
            begin = x;
        }
        dfs(begin);
        // for (int i = 1; i <= n;i++)
        //     printf("%d ", f[i]);
        // printf("\n");
        res += f[begin];
        printf("%lld\n", res);
    }

    return 0;
}