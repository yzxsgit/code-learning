#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N], d[N], ne[N], idx;
int n, m;
int bfs()
{
    memset(d, -1, sizeof(d));
    d[1] = 0;
    queue<int> q;
    q.push(1);
    while (q.size())
    {
        int t = q.front();
        q.pop();
        for (int i = h[t]; i != -1; i = ne[i])
        {
            int j = e[i];
            
            if (d[j] == -1)
            {
                d[j] = d[t] + 1;
                q.push(j);
            }
        }
    }
    return d[n];
}
void add(int a, int b)
{
    e[idx] = b;
    ne[idx] = h[a];
    h[a] = idx++;
}
int main()
{
    memset(h, -1, sizeof(h));
    scanf("%d%d", &n, &m);
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        add(x, y);
    }

    cout << bfs() << endl;

    return 0;
}