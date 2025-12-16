#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
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

int spfa()
{
    memset(dist, 0x3f, sizeof dist);
    dist[1] = 0;

    queue<int> q;
    q.push(1);
    st[1] = true;

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

    return dist[n];
}

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    int ans = spfa();

    if (ans == 0x3f3f3f3f)
        printf("impossible");
    else
        printf("%d", ans);

    return 0;
}