#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int N = 510, P = 810, M = 1450 * 2 + 10, INF = 0x3f3f3f3f;

int h[P], e[M * 2], ne[M * 2], w[M * 2], idx;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int n, p, c;
int dist[P], id[N];
bool st[P];

int spfa(int start)
{
    memset(st, 0, sizeof st);
    memset(dist, 0x3f, sizeof dist);

    queue<int> q;
    dist[start] = 0;
    st[start] = true;
    q.push(start);

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            int d = dist[t] + w[i];
            if (d < dist[j])
            {
                dist[j] = d;
                if(!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }

    int tmp = 0;
    for (int i = 1; i <= n; i++)
    {
        int j = id[i];
        if(dist[j] == INF)
            return INF;
        tmp += dist[j];
    }

    return tmp;
}

int main()
{
    memset(h, -1, sizeof h);

    cin >> n >> p >> c;
    for (int i = 1; i <= n; i++)
        cin >> id[i];

    while (c--)
    {
        int a, b, d;
        cin >> a >> b >> d;
        add(a, b, d);
        add(b, a, d);
    }

    int res = INF;
    for (int i = 1; i <= p; i++)
        res = min(res, spfa(i));

    cout << res << "\n";

    return 0;
}