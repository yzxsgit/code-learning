#include <iostream>
#include <cstring>
#include <deque>

using namespace std;
const int N = 510,
          dx[] = {-1, -1, 1, 1}, dy[] = {-1, 1, 1, -1},
          ix[] = {-1, -1, 0, 0}, iy[] = {-1, 0, 0, -1};
const char cs[] = {"\\/\\/"};

char g[N][N];
int dist[N][N];
bool st[N][N];
int n, m;

int bfs()
{
    deque<pair<int, int>> q;
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);

    q.push_back({0, 0});
    dist[0][0] = 0;
    
    while (q.size())
    {
        auto t = q.front();
        q.pop_front();

        int x = t.first, y = t.second;
        if (x == n && y == m)
            return dist[x][y];

        if (st[x][y])
            continue;
        st[x][y] = true;

        for (int i = 0; i < 4;i++)
        {
            int a = x + dx[i], b = y + dy[i];
            if (a < 0 || a > n || b < 0 || b > m)
                continue;

            int ca = x + ix[i], cb = y + iy[i];
            int w = g[ca][cb] != cs[i];
            int d = dist[x][y] + w;

            if(d < dist[a][b])
            {
                dist[a][b] = d;

                if(w)
                    q.push_back({a, b});
                else
                    q.push_front({a, b});
            }
        }
    }

    return -1;
}

void solve()
{
    scanf("%d%d", &n, &m);

    for (int i = 0; i < n; i++)
        scanf("%s", g[i]);

    if (n + m & 1)
        printf("NO SOLUTION\n");
    else
        printf("%d\n", bfs());

    return;
}

int main()
{
    int T;
    scanf("%d", &T);
    
    while (T--)
    {
        solve();
    }

    return 0;
}