#include <iostream>
#include <cstring>
#include <queue>

using namespace std;
const int N = 2510, M = 6200 * 2 + 10;

int h[N], e[M], ne[M], w[M], idx;
void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int dist[N];
int n, m, S, T;
bool st[N];

void spfa(int start)
{
    memset(dist, 0x3f, sizeof dist);

    queue<int> q;
    q.push(start);
    dist[start] = 0;
    st[start] = true;

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
}

int main()
{
    memset(h, -1, sizeof h);

    cin >> n >> m >> S >> T;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
        add(b, a, c);
    }

    spfa(S);

    cout << dist[T] << "\n";

    return 0;
}