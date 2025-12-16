#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int N = 2e5 + 10;
int h[N * 2], e[N * 2], ne[N * 2], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int n, m;
int dist[N];
bool visited[N];
int bfs()
{
    memset(dist, 0x3f3f3f3f, sizeof dist);
    queue<int> q;
    q.push(1);
    dist[1] = 0;
    visited[1] = true;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (!visited[j])
            {
                visited[j] = true;
                q.push(j);
                dist[j] = dist[t] + 1;
            }
        }
    }

    return dist[n];
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);

    while (m--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    cout << (bfs() <= 2 ? "POSSIBLE" : "IMPOSSIBLE") << "\n";

    return 0;
}