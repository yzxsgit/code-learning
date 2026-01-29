#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 700, M = 100010;

int h[N], e[M], ne[M], w[M], idx;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

double dist[N];
int cnt[N];
bool st[N];
int n;

bool spfa_check(double mid)
{
    memset(dist, 0, sizeof dist);
    memset(st, 0, sizeof st);
    memset(cnt, 0, sizeof cnt);
    queue<int> q;

    for (int i = 0; i < 676; i++)
    {
        st[i] = true;
        q.push(i);
    }

    int count = 0;
    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            if (dist[j] < dist[t] + w[i] - mid)
            {
                dist[j] = dist[t] + w[i] - mid;
                if (++count > 10000)
                    return true;
                cnt[j] = cnt[t] + 1;
                if (cnt[j] > N)
                    return true;
                if (!st[j])
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
        double mid = (l + r) / 2;
        if (spfa_check(mid))
            l = mid;
        else
            r = mid;
    }

    return l;
}

void solve()
{
    memset(h, -1, sizeof h);
    idx = 0;

    char str[1010];
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        int len = strlen(str);
        if (len >= 2)
        {
            int a = (str[0] - 'a') * 26 + str[1] - 'a';
            int b = (str[len - 2] - 'a') * 26 + str[len - 1] - 'a';
            add(a, b, len);
        }
    }

    if (!spfa_check(0))
        puts("No solution");
    else 
    {
        cout << bsearch(0, 1000) << '\n';
    }
}

int main()
{
    while (cin >> n && n)
    {
        solve();
    }

    return 0;
}