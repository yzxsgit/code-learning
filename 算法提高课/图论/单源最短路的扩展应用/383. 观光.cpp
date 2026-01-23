#include <iostream>
#include <cstring>
#include <queue>
#include <algorithm>

using namespace std;

const int N = 1010, M = 1e4 + 10;

struct Ver
{
    int id, type, dist;
    bool operator> (const Ver &W) const
    {
        return dist > W.dist;
    }
};


int n, m, s, f;
int h[N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dist[N][2], cnt[N][2];
bool st[N][2];

int dijkstra()
{
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    memset(dist, 0x3f, sizeof dist);

    priority_queue<Ver, vector<Ver>, greater<Ver>> heap;
    dist[s][0] = 0;
    heap.push({s, 0, 0});
    cnt[s][0] = 1;

    while (heap.size())
    {
        Ver t = heap.top();
        heap.pop();

        int ver = t.id, type = t.type, distance = t.dist, count = cnt[ver][type];
        if(st[ver][type])
            continue;
        st[ver][type] = true;

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j][0] > distance + w[i])
            {
                dist[j][1] = dist[j][0], cnt[j][1] = cnt[j][0];
                heap.push({j, 1, dist[j][1]});
                dist[j][0] = distance + w[i], cnt[j][0] = count;
                heap.push({j, 0, dist[j][0]});
            }
            else if (dist[j][0] == distance + w[i])
            {
                cnt[j][0] += count;
            }
            else if (dist[j][1] > distance + w[i])
            {
                dist[j][1] = distance + w[i], cnt[j][1] = count;
                heap.push({j, 1, dist[j][1]});
            }
            else if (dist[j][1] == distance + w[i])
            {
                cnt[j][1] += count;
            }
        }
    }

    int res = cnt[f][0];
    if(dist[f][0] == dist[f][1] - 1)
        res += cnt[f][1];

    return res;
}

void solve()
{
    memset(h, -1, sizeof h);
    idx = 0;

    cin >> n >> m;
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cin >> s >> f;

    cout << dijkstra() << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }

    return 0;
}