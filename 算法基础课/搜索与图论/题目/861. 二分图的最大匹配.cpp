#include <bits/stdc++.h>
using namespace std;
const int N = 510, M = 1e5 + 10;
int h[N], e[M], ne[M], idx;
int match[N];
int n1, n2, m;
bool st[N];

void add(int x, int y)
{
    e[idx] = y, ne[idx] = h[x], h[x] = idx++;
}

bool find(int u)
{
    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            st[j] = true;
            if (find(match[j]) || !match[j])
            {
                match[j] = u;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    scanf("%d%d%d", &n1, &n2, &m);
    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    int res = 0;

    for (int i = 1; i <= n1; i++)
    {
        memset(st, false, sizeof st);
        if (find(i))
            res++;
    }

    printf("%d\n", res);

    return 0;
}