#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

typedef pair<int,int> PII;

const int N = 2e5 + 10;
int h[N], e[N], ne[N], w[N], idx;
void add(int a,int b,int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}
int dist[N];
int n, m, s;
bool visited[N];

void bfs(int x)
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;

    dist[x] = 0;
    heap.push({0, x});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();
        int ver = t.second;
        if(visited[ver])
            continue;
        visited[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[ver]+w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n, &m, &s);

    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    bfs(s);

    for (int i = 1; i <= n; i++)
        if(dist[i]!= 0x3f3f3f3f)
            printf("%d ", dist[i]);
        else
            printf("-1 ");
    return 0;
}