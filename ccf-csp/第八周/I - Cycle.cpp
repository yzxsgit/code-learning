#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 2e5 + 10;
int h[N], e[N], ne[N], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
bool visited[N];
int dist[N];
int bfs()
{
    queue<int> q;
    q.push(1);
    visited[1] = true;
    dist[1] = 1;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (j == 1)
            {
                return dist[t];
            }
            if (!visited[j])
            {
                dist[j] = dist[t] + 1;
                visited[j] = true;
                q.push(j);
            }
        }
    }

    return -1;
}
int main()
{
    memset(h, -1, sizeof h);
    int n, m;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    cout << bfs();

    return 0;
}