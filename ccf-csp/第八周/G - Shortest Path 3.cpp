#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

const int N = 2e5 + 10;

int h[N * 2], e[N * 2], ne[N * 2], w[N * 2], idx;
void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int n, m;
ll dist[N];
int a[N];
bool visited[N];

void bfs(int x)
{
    memset(dist, 0x3f, sizeof dist);
    queue<int> q;
    q.push(x);
    dist[x] = a[x];
    visited[x] = true;
    
    while (q.size())
    {
        int t = q.front();
        q.pop();
        visited[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] == 0x3f3f3f3f || dist[j] > dist[t] + w[i] + a[j])
            {
                dist[j] = dist[t] + w[i] + a[j];
                if(!visited[j])
                {
                    q.push(j);
                    visited[j] = true;
                }
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    while (m--)
    {
        int x, y, z;
        scanf("%d%d%d", &x, &y, &z);
        add(x, y, z);
        add(y, x, z);
    }

    bfs(1);

    for (int i = 2; i <= n; i++)
        printf("%lld ", dist[i]);

    return 0;
}