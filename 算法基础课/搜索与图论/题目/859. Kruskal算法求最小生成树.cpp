#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 10;
struct Edges
{
    int a, b, w;
} edges[N];
int n, m, res, F[N];
bool cmp(Edges x, Edges y)
{
    return x.w < y.w;
}
int find(int x)
{
    if (F[x] != x)
        F[x] = find(F[x]);

    return F[x];
}
bool Kruskal()
{
    int cnt = 0;
    for (int i = 0; i < m; i++)
    {
        int a = edges[i].a, b = edges[i].b, w = edges[i].w;
        a = find(a);
        b = find(b);
        if (a != b)
        {
            F[a] = b;
            res += w;
            cnt++;
        }
    }
    if (cnt < n - 1)
        return false;
    return true;
}
int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        F[i] = i;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        scanf("%d%d%d", &a, &b, &w);
        edges[i] = {a, b, w};
    }

    sort(edges, edges + m, cmp);

    if (Kruskal())
        printf("%d", res);
    else
        printf("impossible\n");

    return 0;
}