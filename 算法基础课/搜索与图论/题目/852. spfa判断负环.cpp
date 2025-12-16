#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], ne[N], w[N], idx;
int cnt[N], dist[N];
int n, m;
bool st[N];

void add(int x, int y, int z)
{
    e[idx] = y;
    w[idx] = z;
    ne[idx] = h[x];
    h[x] = idx++;
}

bool spfa()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        q.push(i);
        st[i] = true;
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            if(dist[j] > dist[t] + w[i])
            {
                dist[j] = dist[t] + w[i];
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n)
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

int main()
{
    memset(h, -1, sizeof h);
    scanf("%d%d", &n, &m);

    while (m--)
    {
        int a, b, c;
        scanf("%d%d%d", &a, &b, &c);
        add(a, b, c);
    }

    if(spfa())
        puts("Yes");
    else
        puts("No");

    return 0;
}