#include <iostream>
#include <cstring>
#include <iomanip>
#include <queue>

using namespace std;

const int N = 1010, M = 1e4 + 10;

int h[N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int n, m;
double dist[N];
int cnt[N], f[N];
bool st[N];

bool spfa_check(double mid)
{
    memset(dist, 0, sizeof dist);
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
            if (dist[j] < dist[t] + f[t] - mid * w[i])
            {
                dist[j] = dist[t] + f[t] - mid * w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] > n)
                    return true;
                if(!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }

    return false;
}

double bsearch(double l, double r)
{
    while (r - l > 1e-4)
    {
        double mid = (r + l) / 2;
        if (spfa_check(mid))
            l = mid;
        else
            r = mid;
    }

    return l;
}

int main()
{
    memset(h, -1, sizeof h);
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        cin >> f[i];

    for (int i = 0; i < m; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c);
    }

    cout << fixed << setprecision(2) << bsearch(0, 1e6) << "\n";

    return 0;
}