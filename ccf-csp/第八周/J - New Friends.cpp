#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
typedef long long ll;
const int N = 2e5 + 10;
int h[N * 2], e[N * 2], ne[N * 2], idx;
void add(int a,int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}
int n, m;
ll res;
bool visited[N];
int bfs(int x)
{
    int tmp = 0;
    queue<int> q;
    q.push(x);
    visited[x] = true;
    tmp++;
    while (q.size())
    {
        int t = q.front();
        q.pop();

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(!visited[j])
            {
                tmp++;
                q.push(j);
                visited[j] = true;
            }
        }
    }

    return tmp;
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
        add(b, a);
    }

    for (int i = 1; i <= n; i++)
        if(!visited[i])
        {
            int tmp = bfs(i);
            res += (ll)tmp * (tmp - 1);
        }

    res -= m * 2;
    res /= 2;

    printf("%lld", res);

    return 0;
}