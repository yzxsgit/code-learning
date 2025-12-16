#include <iostream>
#include <cstring>

using namespace std;
const int N = 1e4 + 10, M = N * 2;
int h[N], w[M], e[M], ne[M], idx;

void add(int a, int b, int c)
{
    e[idx] = b, w[idx] = c, ne[idx] = h[a], h[a] = idx++;
}

int n, ans;

int dfs(int u,int father)
{
    int dist = 0;
    int d1 = 0, d2 = 0;

    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(j == father) continue;

        int d = dfs(j, u) + w[i];
        dist = max(dist, d);

        if(d >= d1)
            d2 = d1, d1 = d;
        else if(d > d2)
            d2 = d;
    }

    ans = max(ans, d1 + d2);

    return dist;
}

int main()
{
    cin >> n;

    memset(h, -1, sizeof h);
    for (int i = 0; i < n - 1; i++)
    {
        int a, b, c;
        cin >> a >> b >> c;
        add(a, b, c), add(b, a, c);
    }

    dfs(1, -1);

    cout << ans << "\n";

    return 0;
}