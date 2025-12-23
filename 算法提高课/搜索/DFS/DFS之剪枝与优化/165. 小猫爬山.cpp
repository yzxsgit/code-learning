#include <iostream>
#include <algorithm>

using namespace std;
const int N = 20;

int n, m;
int c[N], w[N];
int res = N;

void dfs(int u, int k)
{
    if (u >= res)
        return;
    if (k == n)
    {
        res = u;
        return;
    }

    for (int i = 0; i < u; i++)
        if (w[i] + c[k] <= m)
        {
            w[i] += c[k];
            dfs(u, k + 1);
            w[i] -= c[k];
        }

    w[u] = c[k];
    dfs(u + 1, k + 1);
    w[u] = 0;
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
        cin >> c[i];

    sort(c, c + n, greater<int>());

    dfs(0, 0);

    cout << res << "\n";

    return 0;
}