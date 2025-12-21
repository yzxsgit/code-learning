#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> PII;
const int N = 2e5 + 10;

int h[N], w[N], e[N], ne[N], idx;
int dist[N];
bool st[N];
int n, m;
void add(int a, int b, int c)
{
    w[idx] = c;
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int Dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    dist[1] = 0;
    heap.push({0, 1});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second;

        if (st[ver])
            continue;
        st[ver] = true;

        for (int i = h[ver]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[ver] + w[i])
            {
                dist[j] = dist[ver] + w[i];
                heap.emplace(dist[j], j);
            }
        }
    }

    if (dist[n] == 0x3f3f3f3f)
        return -1;
    return dist[n];
}
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    int ans = Dijkstra();

    printf("%d", ans);

    return 0;
}