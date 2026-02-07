#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 110, M = 1010;

bool g[N][N],st[N];
int n, m, k;
int match[N];

bool find(int x)
{
    for (int i = 0; i < m; i++)
    {
        if (!st[i] && g[x][i])
        {
            st[i] = true;
            if (match[i] == -1 || find(match[i]))
            {   
                match[i] = x;
                return true;
            }
        }
    }

    return false;
}

void solve()
{
    memset(g, 0, sizeof g);
    memset(match, -1, sizeof match);

    cin >> m >> k;

    while (k--)
    {
        int t, a, b;
        cin >> t >> a >> b;
        if (!a || !b) continue;
        g[a][b] = true;
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        memset(st, 0, sizeof st);
        if (find(i))
            res++;
    }

    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    while (cin >> n, n)
    {
        solve();
    }
    return 0;
}