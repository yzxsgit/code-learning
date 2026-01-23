#include <iostream>
#include <queue>
#include <cstring>
#include <vector>

using namespace std;

const int N = 5e4 + 10, M = 5e4 * 3 + 10, INF = 0x3f3f3f3f;

typedef pair<int, int> PII;

int n,mp,mr,S;
int id[N];
int h[N], e[M], ne[M], w[M], idx;

void add(int a,int b,int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dist[N], din[N];
vector<int> block[N];
int bcnt;
bool st[N];
queue<int> q;

void dfs(int u, int bid)
{
    id[u] = bid, block[bid].push_back(u);

    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(!id[j])
            dfs(j, bid);
    }
}

void dijkstra(int start)
{
    priority_queue<PII, vector<PII>, greater<PII>> heap;

    for (auto u : block[start])
        heap.push({dist[u], u});

    while (heap.size())
    {
        auto t = heap.top();
        heap.pop();

        int ver = t.second, distance = t.first;
        if (st[ver])
            continue;
        st[ver] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if(id[j] != id[ver] && --din[id[j]] == 0)
                q.push(id[j]);
            if(dist[j] > distance + w[i])
            {
                dist[j] = distance + w[i];
                if(id[j] == id[ver])
                    heap.push({dist[j], j});
            }
        }
    }
}

void topsort()
{
    memset(dist, 0x3f, sizeof dist);
    dist[S] = 0;

    for (int i = 1; i <= bcnt; i++)
        if(!din[i])
            q.push(i);

    while (q.size())
    {
        auto t = q.front();
        q.pop();
        dijkstra(t);
    }
}

int main()
{
    cin >> n >> mr >> mp >> S;

    memset(h, -1, sizeof h);

    while (mr--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    for (int i = 1; i <= n; i++)
        if(!id[i])
            dfs(i,++bcnt);

    while (mp--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        din[id[b]]++;
    }

    topsort();

    for (int i = 1; i <= n; i++)
        if (dist[i] > INF / 2) cout << "NO PATH" << endl;
        else cout << dist[i] << endl;
    
    return 0;
}