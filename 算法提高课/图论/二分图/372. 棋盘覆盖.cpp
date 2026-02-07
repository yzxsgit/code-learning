#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 110;

bool g[N][N], st[N][N];
PII match[N][N];
int dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
int n, m;

bool find(int x, int y)
{
    for (int i = 0; i < 4; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (a < 1 || a > n || b < 1 || b > n) continue;
        if (g[a][b] || st[a][b]) continue;
        st[a][b] = true;
        PII t = match[a][b];
        if (t.first == -1 || find(t.first, t.second))
        {
            match[a][b] = {x, y};
            return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }

    memset(match, -1, sizeof match);

    int res = 0;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            if ((i + j) % 2 && !g[i][j])
            {
                memset(st, 0, sizeof st);
                if (find(i, j))
                    res++;
            }

    cout << res << '\n';

    return 0;
}