#include <bits/stdc++.h>
using namespace std;
const int N = 20;
int path[N];
bool col[N], dg[N], udg[N];
int n;
void dfs(int u)
{
    if(u == n)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
                if(path[i] == j)
                    printf("Q");
                else
                    printf(".");
            printf("\n");
        }
        printf("\n");
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if(!col[i] && !dg[u+i] && !udg[i+n-u])
        {
            path[u] = i;
            col[i] = dg[u + i] = udg[i + n - u] = true;
            dfs(u + 1);
            col[i] = dg[u + i] = udg[i + n - u] = false;
        }
    }
}
int main()
{
    scanf("%d", &n);

    dfs(0);

    return 0;
}