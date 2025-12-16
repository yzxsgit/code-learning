#include <iostream>
#include <algorithm>

using namespace std;

int c[100], sum[100];
bool flag[100];

int ans = 1e9;
int n, m;
void dfs(int u, int v)
{
    if (v >= ans)
        return;

    if (u == n)
    {
        ans = v;
        return;
    }
    for (int i = 0; i < v; i++)
    {
        if (sum[i] + c[u] <= m)
        {
            sum[i] += c[u];
            dfs(u + 1, v);
            sum[i] -= c[u];
        }
    }
    sum[v] = c[u];
    dfs(u + 1, v + 1);
    sum[v] = 0;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        cin >> c[i];
    sort(c, c + n);
    dfs(0, 0);
    printf("%d", ans);
    return 0;
}