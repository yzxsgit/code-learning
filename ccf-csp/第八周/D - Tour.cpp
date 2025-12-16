#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 2010;
int h[N], e[N], ne[N], idx;
void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int n, m;
int res;
bool visited[N];
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = true, res++;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!visited[j])
            {
                res++;
                q.push(j);
                visited[j] = true;
            }
        }
    }
}
int main()
{
    memset(h, -1, sizeof h);

    scanf("%d%d", &n, &m);
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        add(a, b);
    }

    for (int i = 1; i <= n; i++)
    {
        memset(visited, false, sizeof visited);
        bfs(i);
    }

    cout << res;

    return 0;
}