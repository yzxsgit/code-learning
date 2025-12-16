#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int N = 1e5 + 10;

int h[N * 2], e[N * 2], ne[N * 2], idx;
void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int n, q;
int color[N];
void bfs()
{
    memset(color, -1, sizeof color);
    queue<int> q;
    q.push(1);
    color[1] = 1;
    while(q.size())
    {
        int t = q.front();
        q.pop();

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(color[j] == -1)
            {
                color[j] = 1 - color[t];
                q.push(j);
            }
        }
    }

}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &q);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }
    bfs();
    while (q--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if (color[x] == color[y])
            printf("Town\n");
        else
            printf("Road\n");
    }

    return 0;
}