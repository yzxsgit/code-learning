#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 510, M = 5210;

int h[N], ne[M], e[M], w[M], idx;

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int n, m1, m2;
int dist[N], cnt[N];
bool st[N];

bool spfa()
{
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    queue<int> q;

    for (int i = 1; i <= n; i++)
    {
        q.push(i);
        st[i] = true;
    }

    while (!q.empty())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if (cnt[j] > n)
                    return true;
                if(!st[j])
                {
                    q.push(j);
                    st[j] = true;
                } 
            }
        }
    }

    return false;
}

void solve() 
{
    cin >> n >> m1 >> m2;
    memset(h, -1, sizeof h);
    idx = 0;

    for (int i = 1; i <= m1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    for (int i = 1; i <= m2; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, -c);
    }

    cout << (spfa() ? "YES\n" : "NO\n");
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}