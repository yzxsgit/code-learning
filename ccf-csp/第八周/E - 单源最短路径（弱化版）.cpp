#include <bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int h[N], ne[N], e[N], w[N], idx;
int dist[N];
bool st[N];
int n, m;
void add(int x, int y, int z)
{
    e[idx] = y;
    w[idx] = z;
    ne[idx] = h[x];
    h[x] = idx++;
}

void spfa(int x)
{
    memset(dist, 0x3f, sizeof dist);
    dist[x] = 0;

    queue<int> q;
    q.push(x);
    st[x] = true;

    while (q.size())
    {
        int t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if (!st[j])
                {
                    q.push(j);
                    st[j] = true;
                }
            }
        }
    }
}

int main()
{
    int s;
    memset(h, -1, sizeof h);
    scanf("%d%d%d", &n, &m, &s);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    spfa(s);
    for (int i = 1; i <= n; i++)
        if (dist[i] < 0x3f3f3f3f)
            printf("%d ", dist[i]);
        else
            printf("%d ", INT_MAX);
    return 0;
}