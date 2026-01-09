#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 5e4 + 10, M = 2e5 + 10, INF = 0x3f3f3f3f;
typedef pair<int, int> PII;

int h[N], ne[M], e[M], w[M], idx;
void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dist[6][N];
bool st[N];
int n, m;
int source[6];

void dijkstra(int start, int dist[])
{
    memset(dist, 0x3f, N * 4);

    dist[start] = 0;

    memset(st, 0, sizeof st);

    priority_queue<PII, vector<PII>, greater<PII>> heap;
    heap.push({0, start});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;
        if (st[ver]) continue;
        st[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.push({dist[j], j});
            }
        }
    }
}

int dfs(int u, int start, int distance)
{
    if (u > 5)
        return distance;

    int res = INF;

    for (int i = 1; i <= 5; i++)
        if(!st[i])
        {
            int next = source[i];
            st[i] = true;
            res = min(res, dfs(u + 1, i, distance + dist[start][next]));
            st[i] = false;
        }

    return res;
}

int main()
{
    scanf("%d%d", &n, &m);

    source[0] = 1;

    for (int i = 1; i <= 5; i++)
        scanf("%d", &source[i]);

    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c), add(b, a, c);
    }

    for (int i = 0; i < 6; i++)
        dijkstra(source[i], dist[i]);

    memset(st, 0, sizeof st);

    printf("%d\n", dfs(1, 0, 0));

    return 0;
}