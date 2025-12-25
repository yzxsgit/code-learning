#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 50;
typedef long long LL;

int n, m, k, cnt = 1, res;
int g[N];
int w[1 << 26];

void dfs1(int u, int s) 
{
    if(u == k)
    {
        w[cnt++] = s;
        return;
    }


    dfs1(u + 1, s);
    if ((LL) s + g[u] > m)
        return;
    dfs1(u + 1, s + g[u]);
}

void dfs2(int u, int s)
{
    if(u >= n)
    {
        int l = 0, r = cnt - 1;
        while (l < r)
        {
            int mid = l + r + 1 >> 1;
            if(w[mid] <= m - s)
                l = mid;
            else
                r = mid - 1;
        }
        res = max(res, w[l] + s);
        return;
    }

    dfs2(u + 1, s);
    if((LL) s + g[u] > m)
        return;
    dfs2(u + 1, s + g[u]);
}

int main()
{
    cin >> m >> n;

    for (int i = 0; i < n; i++)
        cin >> g[i];

    sort(g, g + n, greater<int>());

    k = n / 2;

    dfs1(0, 0);

    sort(w, w + cnt);

    cnt = unique(w, w + cnt) - w;

    dfs2(k, 0);

    cout << res << "\n";

    return 0;
}