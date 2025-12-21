#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;
typedef pair<int, int> PII;
const int N = 3e5 + 10, M = 6e5 + 10;
int h[N], e[M], ne[M], idx;

void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int father[N];
int find(int x)
{
    if(father[x] != x)
        father[x] = find(father[x]);

    return father[x];
}

int n, m, q;

void init()
{
    memset(h, -1, sizeof h);
    for (int i = 1; i <= n; i++)
        father[i] = i;
}

int dist[N];
bool state[N];

void dijkstra(int st)
{
    memset(dist, 0x3f, sizeof dist);
    priority_queue<PII, vector<PII>, greater<PII>> heap;
    dist[st] = 0;
    heap.push({0, st});

    while (!heap.empty())
    {
        PII t = heap.top();
        heap.pop();

        int ver = t.second;
        if (state[ver])
            continue;
        state[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[ver] + 1)
            {
                dist[j] = dist[ver] + 1;
                heap.emplace(dist[j], j);
            }
        }
    }
}

int main()
{
    scanf("%d%d%d", &n, &m, &q);

    init();

    vector<PII> edges;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        int A, B;
        scanf("%d", &A);
        for (int j = 0; j < A; j++)
        {
            int val;
            scanf("%d",&val);
            if(j == 0)
                a = val;
            else
                father[find(val)] = find(a);
        }

        scanf("%d", &B);
        for (int j = 0; j < B; j++)
        {
            int val;
            scanf("%d",&val);
            if(j == 0)
                b = val;
            else
                father[find(val)] = find(b);
        }
        if (A > 0 && B > 0)
            edges.push_back({a, b});
    }

    for (int i = 0; i < edges.size(); i++)
    {
        int l = find(edges[i].first), r = find(edges[i].second);
        if (l != r)
        {
            add(l, r);
            add(r, l);
        }
    }

    int st = find(1);

    dijkstra(st);

    for (int i = 1; i <= q; i++)
    {
        int ed;
        scanf("%d", &ed);
        int ed_f = find(ed);
        if(dist[ed_f] == 0x3f3f3f3f)
            printf("-1\n");
        else if(ed_f == st && ed != 1)
            printf("2\n");
        else
            printf("%d\n", dist[ed_f]);
    }

    return 0;
}