#include <iostream>
#include <cmath>

using namespace std;
const int N = 25, INF = 1e9;

int mins[N], minv[N];
int n, m;
int R[N], H[N];

int res = INF;

void dfs(int u, int s, int v)
{
    if (v + minv[u] > m)
        return;
    if (s + mins[u] >= res)
        return;
    if (s + 2 * (m - v) / R[u + 1] >= res)
        return;

    if(!u)
    {
        if(v == m)
            res = s;
        return;
    }

    for (int r = min(R[u + 1] - 1, (int)sqrt(m - v)); r >= u; r--)
        for (int h = min(H[u + 1] - 1, (m - v) / r / r); h >= u; h--)
        {
            int t = 0;
            if(u == n)
                t = r * r;
            R[u] = r;
            H[u] = h;
            dfs(u - 1, s + 2 * r * h + t, v + r * r * h);
        }
}

int main()
{
    cin >> m >> n;

    for (int i = 1; i <= n; i++)
    {
        mins[i] = mins[i - 1] + i * i * 2;
        minv[i] = minv[i - 1] + i * i * i;
    }
    
    R[n + 1] = H[n + 1] = INF;

    dfs(n, 0, 0);

    if(res == INF)
        cout << "0\n";
    else
        cout << res << "\n";

    return 0;
}