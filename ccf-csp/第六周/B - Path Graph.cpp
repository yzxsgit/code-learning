#include <iostream>
#include <cstring>

using namespace std;

const int N = 4e5 + 10;

int h[N], ne[N], e[N], idx, deg[N];
void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++, deg[a]++;
}

int q[N],flag[N];
void bfs(int x)
{
    int head = 0,tail = 0;
    q[tail++] = x;
    flag[x] = true;
    while (head < tail)
    {
        int t = q[head++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!flag[j])
            {
                flag[j] = true;
                q[tail++] = j;
            }
        }
    }
}
int n, m;
int main()
{
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);
    if(n!=m+1)
    {
        printf("No\n");
        return 0;
    }

    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    bfs(1);
    bool ans = true;
    for (int i = 1; i <= n; i++)
        if(!flag[i])
            ans = false;

    int degree = 0;

    for (int i = 1; i <= n; i++)
        if(deg[i] == 1)
            degree++;
        else if(deg[i] != 2)
        {
            ans = false;
            break;
        }

    if(ans && degree == 2)
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}