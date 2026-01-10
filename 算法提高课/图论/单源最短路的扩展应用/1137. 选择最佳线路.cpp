#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1e3 + 10, M = 2e4 + 10;

int h[N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int n, m, s, k;
int dist[N];
bool st[N];

void spfa()
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);

    dist[0] = 0;
    queue<int> q;
    q.push(0);
    st[0] = true;

    while (q.size())
    {
        auto t = q.front();
        q.pop();

        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                if(!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }    
            }
        }
    }
}

void solve()
{
    memset(h, -1, sizeof h);
    idx = 1;
    
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cin >> k;
    while (k--)
    {
        int a;
        cin >> a;
        add(0, a, 0);
    }

    spfa();

    cout << (dist[s] == 0x3f3f3f3f ? -1 : dist[s]) << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    while (cin >> n >> m >> s)
    {
        solve();
    }

    return 0;
}