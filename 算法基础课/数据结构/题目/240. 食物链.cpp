#include <bits/stdc++.h>
using namespace std;
const int N = 5e4 + 10;
int p[N], d[N];
int n, m;
int find(int x)
{
    if(p[x] != x)
    {
        int t = find(p[x]);
        d[x] += d[p[x]];
        p[x] = t;
    }
    return p[x];
}

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        p[i] = i;
    int ans = 0;
    while (m--)
    {
        int t, a, b;
        scanf("%d%d%d", &t, &a, &b);
        if (a > n || b > n)
            ans++;
        else
        {
            int pa = find(a), pb = find(b);
            if(t == 1)
            {
                if (pa == pb && (d[a] - d[b]) % 3)
                    ans++;
                else if (pa != pb)
                {
                    d[pa] = d[b] - d[a];
                    p[pa] = pb;
                }
            }
            else
            {
                if (pa == pb && (d[a] -d[b] - 1) % 3)
                    ans++;
                else if(pa != pb)
                {
                    d[pa] = 1 + d[b] - d[a];
                    p[pa] = pb;
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}