#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int q[N], h[N], e[N], ne[N], l[N], r[N], idx;
int n, m;
bool bfs()
{
    int head = 0, tail = 0;
    for (int i = 1; i <= n; i++)
    {
        if (l[i] == 0)
            q[tail++] = i;
    }
    while(head < tail)
    {
        int t = q[head++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            l[j]--;
            if(l[j] == 0)
                q[tail++] = j;
        }
    }

    return tail == n;
}
void add(int a,int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int main()
{
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        l[y]++;
    }

    if(bfs())
    {
        for (int i = 0; i < n; i++)
            printf("%d ", q[i]);
        printf("\n");
    }
    else
        printf("-1\n");
}