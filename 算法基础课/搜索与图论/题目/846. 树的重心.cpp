#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int h[N], e[N * 2], ne[N * 2], idx, ans = N, n;
bool st[N];
void add(int x, int y)
{
    ne[idx] = h[x];
    h[x] = idx;
    e[idx++] = y;
}
int dfs(int u)
{
    st[u] = true;

    int sum = 1, res = 0;

    for (int i = h[u]; i != -1; i = ne[i])
    {
        int j = e[i];
        if (!st[j])
        {
            int s = dfs(j);
            res = max(s, res);
            sum += s;
        }
    }
    res = max(n - sum, res);

    ans = min(ans, res);

    return sum;
}
int main()
{
    memset(h, -1, sizeof(h));
    int a, b;
    scanf("%d", &n);
    for (int i = 0; i < n - 1; i++)
    {
        scanf("%d%d", &a, &b);
        add(a, b);
        add(b, a);
    }

    dfs(1);

    cout << ans << endl;

    return 0;
}