#include <iostream>
#include <cstring>

using namespace std;

const int N = 4e3 + 10;
int h[N], e[N], ne[N], idx;
void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int q[N], flag[N];
int bfs(int x)
{
    int res = 0;
    memset(flag, false, sizeof flag);
    int head = 0, tail = 0;
    q[tail++] = x;
    flag[x] = true;
    res++;
    while (head < tail)
    {
        int t = q[head++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!flag[j])
            {
                res++;
                flag[j] = true;
                q[tail++] = j;
            }
        }
    }

    return res;
}
int n, m;
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans += bfs(i);

    printf("%d", ans);

    return 0;
}