#include <iostream>
#include <deque>
#include <cstring>
#include <set>

using namespace std;

const int N = 11, M = 400, P = 1 << 10;

typedef pair<int, int> PII;

int h[N * N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c) 
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int n, m, p, k;
int g[N][N];
int dist[N * N][P], key[N * N];
bool st[N * N][P];
set<PII> edges;

void init()
{
    memset(h, -1, sizeof h);

    for (int i = 1, t = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            g[i][j] = t++;
}

void build()
{
    int dx[] = {-1, 0, 1, 0}, dy[] = {0, -1, 0, 1};

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int u = 0; u < 4; u++)
            {
                int x = i + dx[u], y = j + dy[u];
                if (!x || !y || x > n || y > m)
                    continue;
                int a = g[i][j], b = g[x][y];
                if (!edges.count({a, b}))
                    add(a, b, 0);
            }
}

int bfs()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1][0] = 0;
    deque<PII> q;
    q.push_back({1, 0});

    while (q.size())
    {
        auto t = q.front();
        q.pop_front();

        int ver = t.first, state = t.second;
        if (st[ver][state]) 
            continue;
        st[ver][state] = true;
        if(ver == n * m)
            return dist[n * m][state];

        if(key[ver])
        {
            int new_state = state | key[ver];
            if(dist[ver][new_state] > dist[ver][state])
            {
                dist[ver][new_state] = dist[ver][state];
                q.push_front({ver, new_state});
            }
        }

        for (int i = h[ver]; ~i; i = ne[i])
        {
            int j = e[i];
            if(w[i] && !(state >> w[i] - 1 & 1))
                continue;
            if(dist[j][state] > dist[ver][state] + 1)
            {
                dist[j][state] = dist[ver][state] + 1;
                q.push_back({j, state});
            }
        }
    }

    return -1;
}

int main()
{
    cin >> n >> m >> p >> k;

    init();

    while (k--)
    {
        int x1, y1, x2, y2, door;
        cin >> x1 >> y1 >> x2 >> y2 >> door;
        int a = g[x1][y1], b = g[x2][y2];
        edges.insert({a, b}), edges.insert({b, a});
        if(door)
            add(a, b, door), add(b, a, door);
    }

    build();

    int s;
    cin >> s;
    while (s--)
    {
        int x, y, c;
        cin >> x >> y >> c;
        key[g[x][y]] |= 1 << c - 1;
    }

    cout << bfs() << "\n";

    return 0;
}