#include <iostream>
#include <deque>
#include <cstring>

using namespace std;

const int N = 1010, M = 2e5 + 10;

int n, m, k;
int h[N], ne[M], w[M], e[M], idx;

void add(int a,int b,int c)
{
    e[idx] = b, ne[idx] = h[a], w[idx] = c, h[a] = idx++;
}

int dist[N];
bool st[N];

bool check(int bound)
{
    memset(dist, 0x3f, sizeof dist);
    memset(st, 0, sizeof st);

    deque<int> q;
    q.push_back(1);
    dist[1] = 0;

    while (q.size())
    {
        int t = q.front();
        q.pop_front();

        if (st[t])
            continue;
        st[t] = true;

        for (int i = h[t]; ~i; i = ne[i])
        {
            int j = e[i];
            int x = w[i] > bound;
            if (dist[j] > dist[t] + x)
            {
                dist[j] = dist[t] + x;
                if(x)
                    q.push_back(j);
                else
                    q.push_front(j);
            }
        }
    }

    return dist[n] > k;
}

int bsearch(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid;
    }
}

int main()
{
    cin >> n >> m >> k;

    memset(h, -1, sizeof h);
    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    int res = bsearch(0, 1e6 + 1);

    cout << (res == 1e6 + 1 ? -1 : res) << "\n";

    return 0;
}