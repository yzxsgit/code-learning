#include <bits/stdc++.h>

using namespace std;

const int N = 1e5 + 10, M = 31 * 1e5 + 10;
int son[M][2], a[N], idx = 0;

void insert(int x)
{
    int p = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (!son[p][u])
            son[p][u] = ++idx;
        p = son[p][u];
    }
}
int search(int x)
{
    int p = 0, res = 0;
    for (int i = 30; i >= 0; i--)
    {
        int u = x >> i & 1;
        if (son[p][!u])
        {
            p = son[p][!u];
            res = res * 2 + 1;
        }
        else
        {
            p = son[p][u];
            res = res * 2;
        }
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        insert(a[i]);
    }
    int res = 0;
    for (int i = 0; i < n; i++)
    {
        res = max(res, search(a[i]));
    }
    printf("%d", res);
    return 0;
}