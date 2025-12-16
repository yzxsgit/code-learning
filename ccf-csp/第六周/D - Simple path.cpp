#include <iostream>
#include <cstring>

using namespace std;

const int N = 4e5 + 10;
int h[N], ne[N], e[N], idx;
void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int q[N], flag[N], l[N];
void bfs(int a,int b)
{
    int head = 0, tail = 0;
    q[tail++] = a;
    flag[a] = true;
    while (head < tail)
    {
        int t = q[head++];
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (j == b)
            {
                l[j] = t;
                return;
            }
            if(l[j] == t)
                continue;
            else if(!flag[j])
            {
                l[j] = t;
                flag[j] = true;
                q[tail++] = j;
            }
        }
    }
}
int main()
{
    memset(h, -1, sizeof h);
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);

    for (int i = 0; i < n - 1;i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
        add(y, x);
    }

    bfs(b, a);

    int out = a;
    printf("%d ", a);
    do
    {
        out = l[out];
        printf("%d ",out);
    } while (out != b);

    return 0;
}