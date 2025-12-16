#include <iostream>
#include <cstring>

using namespace std;

const int N = 5e4 + 10;

int sum[N];
int h[N], e[N], ne[N], idx;
bool st[N];

void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int n;
int ans;

int dfs(int u)
{
    st[u] = true;

    int d1 = 0, d2 = 0;
    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if(!st[j])
        {
            int d = dfs(j);
            if(d >= d1)
                d2 = d1, d1 = d;
            else
                d2 = max(d2, d);
        }
    }

    ans = max(d1 + d2, ans);

    return d1 + 1;
}

int main()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        for (int j = 2; j <= n / i; j++)
            sum[i * j] += i;

    memset(h, -1, sizeof h);

    for (int i = 1; i <= n; i++)
        if(sum[i] < i)
            add(sum[i], i);

    for (int i = 1; i <= n; i++)
        if(!st[i])
            dfs(i);

    cout << ans << "\n";

    return 0;
}