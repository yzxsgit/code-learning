#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int inf = 0x3f3f3f3f;

int n;
vector<vector<PII>> g;
vector<int> dist;
vector<bool> vis;

void dijkstra(int start)
{
    dist.assign(n + 1, inf);
    vis.assign(n + 1, false);
    priority_queue<PII, vector<PII>, greater<PII>> pq;
    dist[start] = 0;
    pq.push({0, start});

    while (pq.size())
    {
        auto t = pq.top();
        pq.pop();
        int d = t.first, u = t.second;
        if (vis[u])
            continue;
        if (d > dist[u])
            continue;
        vis[u] = true;

        for (auto &[v, w] : g[u])
        {
            if (dist[v] > d + w)
            {
                dist[v] = d + w;
                pq.push({dist[v], v});
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, s;
    cin >> n >> m >> s;

    g.resize(n + 1);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
    }

    dijkstra(s);

    for (int i = 1; i <= n; i++)
        cout << (dist[i] != inf ? dist[i] : -1) << (i == n ? '\n' : ' ');

    return 0;
}