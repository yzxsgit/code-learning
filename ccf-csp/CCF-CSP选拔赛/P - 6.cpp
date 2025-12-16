#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e5 + 10;
int h[N], e[N], ne[N], idx;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
char a[N];
int n;
bool visited[N];
int res = 0;
void bfs(int x)
{
    queue<int> q;
    q.push(x);
    visited[x] = true;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (a[t] == a[j])
                res++;
            else if (!visited[j])
            {
                visited[j] = true;
                q.push(j);
            }
        }
    }
}
int main()
{
    memset(h, -1, sizeof h);
    scanf("%d", &n);
    scanf("%s", a + 1);
    for (int i = 1; i < n; i++)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }

    for (int i = 1; i <= n; i++)
        if (!visited[i])
            bfs(i);

    cout << res << endl;

    return 0;
}