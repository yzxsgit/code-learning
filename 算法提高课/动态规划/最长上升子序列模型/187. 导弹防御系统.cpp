#include <iostream>

using namespace std;
const int N = 60;
int up[N], down[N];
int h[N];
int n, ans;
void dfs(int u,int su,int sd)
{
    if (su + sd >= ans)
        return;
    if (u == n)
    {
        ans = su + sd;
        return;
    }

    int k = 0;
    while (k < su && h[u] <= up[k])
        k++;
    int t = 0;
    if(k == su)
    {
        up[k] = h[u];
        dfs(u + 1, su + 1, sd);
        up[k] = t;
    }
    else 
    {
        t = up[k];
        up[k] = h[u];
        dfs(u + 1, su, sd);
        up[k] = t;
    }

    k = 0;
    while (k < sd && h[u] >= down[k])
        k++;
    t = 0;
    if(k == sd)
    {
        down[k] = h[u];
        dfs(u + 1, su, sd + 1);
        down[k] = t;
    }
    else 
    {
        t = down[k];
        down[k] = h[u];
        dfs(u + 1, su, sd);
        down[k] = t;
    }
}
int main()
{
    while (scanf("%d",&n),n)
    {
        ans = n;
        for (int i = 0; i < n; i++)
            scanf("%d", &h[i]);

        dfs(0, 0, 0);

        printf("%d\n", ans);
    }

}