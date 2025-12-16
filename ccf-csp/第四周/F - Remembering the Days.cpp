#include <bits/stdc++.h>
using namespace std;

const int N = 11;
int h[N][N];
int n, m ,ans;
bool st[N];
void dfs(int x ,int res)
{
    for (int i = 1; i <= n; i++)
    {
        if (h[x][i] != 0 && !st[i])
        {
            st[i] = true;
            dfs(i,res+h[x][i]);
            st[i] = false;
        }
    }
    ans = max(ans, res);
}

int main()
{

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b, t;
        scanf("%d%d%d", &a, &b, &t);
        h[a][b] = h[b][a] = max(h[a][b], t);
    }

    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 1; j <= n; j++)
    //         printf("%d ",h[i][j]);
    //     puts("");
    // }

    for (int i = 1; i <= n; i++)
    {
        st[i] = true;
        dfs(i, 0);
        st[i] = false;
    }

    printf("%d\n", ans);

    return 0;
}