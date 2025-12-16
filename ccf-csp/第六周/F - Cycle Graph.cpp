#include <iostream>
#include <cstring>
#include <vector>
#include <queue>

using namespace std;

const int N = 2e5 + 10;
const int M = 4e5 + 10;

int h[N], ne[M], e[M], deg[N], idx;
bool visited[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
    deg[a]++;
}

// BFS检查连通性
bool isConnected(int n)
{
    int start = 1;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] > 0)
        {
            start = i;
            break;
        }
    }

    queue<int> q;
    q.push(start);
    visited[start] = true;
    int count = 0;

    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        count++;

        for (int i = h[u]; i != -1; i = ne[i])
        {
            int v = e[i];
            if (!visited[v])
            {
                visited[v] = true;
                q.push(v);
            }
        }
    }

    return count == n;
}

int main()
{
    int n, m, a, b;
    scanf("%d%d", &n, &m);

    memset(h, -1, sizeof(h));

    for (int i = 0; i < m; i++)
    {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    if (n != m)
    {
        printf("No\n");
        return 0;
    }

    bool flag = true;
    for (int i = 1; i <= n; i++)
    {
        if (deg[i] != 2)
        {
            flag = false;
            break;
        }
    }

    if (flag)
    {
        flag = isConnected(n);
    }

    if (flag)
    {
        printf("Yes\n");
    }
    else
    {
        printf("No\n");
    }

    return 0;
}