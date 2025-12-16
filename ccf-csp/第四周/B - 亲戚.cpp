#include <bits/stdc++.h>
using namespace std;

const int N = 5010;

int n, m, p;
int f[N];

int find(int x)
{
    if (f[x] != x)
        f[x] = find(f[x]);

    return f[x];
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);

    for (int i = 1; i <= n; i++)
        f[i] = i;

    int a, b;
    while (m--)
    {
        scanf("%d%d", &a, &b);

        a = find(a);
        b = find(b);

        f[a] = b;
    }

    while (p--)
    {
        scanf("%d%d", &a, &b);
        if (find(a) == find(b))
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}