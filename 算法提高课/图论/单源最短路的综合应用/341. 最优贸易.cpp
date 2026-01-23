#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

const int N = 1e5 + 10, M = 2e6 + 10;

int n, m;
int dmin[N], dmax[N];
int hs[N], ht[N], e[M], ne[M], idx;
int w[N];
bool st[N];

void add(int h[], int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

void spfa(int h[], int dist[], bool flag)
{
    memset(st, false, sizeof st);
    queue<int> q;
    if(!flag)
    {
        memset(dist, 0x3f, sizeof dmin);
        q.push(1);
        dist[1] = w[1];
    }
    else 
    {
        memset(dist, -0x3f, sizeof dmax);
        q.push(n);
        dist[n] = w[n];
    }

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;
        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (!flag && dist[j] > min(dist[t], w[j]) || flag && dist[j] < max(dist[t], w[j]))
            {
                if (!flag)
                    dist[j] = min(dist[t], w[j]);
                else
                    dist[j] = max(dist[t], w[j]);
                if(!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
}

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    memset(hs, -1, sizeof hs);
    memset(ht, -1, sizeof ht);

    while (m--)
    {
        int a, b, flag;
        scanf("%d%d%d", &a, &b, &flag);
        add(hs, a, b), add(ht, b, a);
        if(flag == 2)
            add(ht, a, b), add(hs, b, a);
    }

    spfa(hs, dmin, 0);
    spfa(ht, dmax, 1);

    int res = 0;

    for (int i = 1; i <= n; i++)
        res = max(dmax[i] - dmin[i], res);

    printf("%d\n", res);

    return 0;
}