#include <bits/stdc++.h>
using namespace std;

const int N = 310, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};

int h[N][N], f[N][N];
int n, m;

int dp(int x,int y)
{
    int &v = f[x][y];
    if(v != -1)
        return v;

    v = 1;

    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if(a > 0 && a <= n && b > 0 && b <= m && h[x][y] > h[a][b])
            v = max(v, dp(a, b) + 1);
    }

    return v;
}

int main()
{
    memset(f, -1, sizeof f);

    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            scanf("%d", &h[i][j]);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            ans = max(ans, dp(i, j));

    printf("%d\n",ans);

    return 0;
}