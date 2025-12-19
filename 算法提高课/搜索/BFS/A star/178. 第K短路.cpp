#include <iostream>
#include <unordered_map>
#include <cstring>
#include <queue>

using namespace std;
const int N = 1e3 + 10, M = 2e5 + 10;
struct III{
    int x, y, z;

    bool operator>(const III& other) const
    {
        return x > other.x;
    }
};

int h[N], rh[N], e[M], ne[M], w[M], idx;
void add(int *h, int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int S, T, K;
int n, m;
int dist[N];
bool st[N];

void dijkstra()
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);
    priority_queue<III, vector<III>, greater<III>> heap;
    heap.push({0, T, 0});
    dist[T] = 0;

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int x = t.y;
        if(st[x])
            continue;
        st[x] = true;

        for (int i = rh[x]; ~i; i = ne[i])
        {
            int j = e[i];

            if (dist[j] > dist[x] + w[i])
            {
                dist[j] = dist[x] + w[i];
                heap.push({dist[j], j, 0});
            }
        }
    }
    return;
}

int astar()
{
    priority_queue<III, vector<III>, greater<III>> heap;
    heap.push({dist[S], 0, S});

    int cnt[N];
    memset(cnt, 0, sizeof cnt);

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int x = t.z, d = t.y;
        cnt[x]++;
        if(cnt[T] == K)
            return d;

        for (int i = h[x]; ~i; i = ne[i])
        {
            int j = e[i];
            if (cnt[j] < K)
                heap.push({d + w[i] + dist[j], d + w[i], j});
        }
    }

    return -1;
}

int main()
{
    scanf("%d%d", &n, &m);
    memset(h, -1, sizeof h);
    memset(rh, -1, sizeof rh);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(h, a, b, c);
        add(rh, b, a, c);
    }

    scanf("%d%d%d", &S, &T, &K);
    
    dijkstra();
    if(S == T)
        K++;
    cout << astar() << "\n";

    return 0;
}