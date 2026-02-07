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
int dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2};
int dy[8] = {1, 2, 2, 1, -1, -2, -2, -1};

bool st[N][N], g[N][N];
PII match[N][N];
int n, m, k;

bool find(int x, int y)
{
    for (int i = 0; i < 8; i++)
    {
        int a = x + dx[i], b = y + dy[i];
        if (g[a][b]) continue;
        if (a < 1 || a > n || b < 1 || b > m) continue;
        if (st[a][b]) continue;
        PII t = match[a][b];
        st[a][b] = true;
        if (t.first == 0 || find(t.first, t.second))
        {
            match[a][b] = {x, y};
            return true;
        }
    }

    return false;
}

int main()
{
    // ios::sync_with_stdio(false);
    // cin.tie(0), cout.tie(0);

    cin >> n >> m >> k;

    for (int i = 0; i < k; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }

    int res = 0;
    for (int i = 1; i <= n; i ++ )
        for (int j = 1; j <= m; j ++ )
        {
            if (g[i][j] || (i + j) % 2) continue;
            memset(st, 0, sizeof st);
            if (find(i, j)) res ++ ;
        }

    cout << n * m - k - res << '\n';

    return 0;
}