#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

int n, m;
vector<vector<bool>> g, visited;

int dx[] = {-1, 0, 1, 0}, dy[] = {0, 1, 0, -1};
int stx, sty, edx, edy;
int res = 0;

void dfs(int x, int y)
{
    if (x == edx && y == edy)
    {
        res++;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx <= 0 || ny <= 0 || nx > n || ny > m || !g[nx][ny])
            continue;
        if(!visited[nx][ny])
        {
            visited[nx][ny] = true;
            dfs(nx, ny);
            visited[nx][ny] = false;
        }
    }   
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> n >> m >> t;

    cin >> stx >> sty >> edx >> edy;

    g.assign(n + 1, vector<bool>(m + 1, true));
    visited.assign(n + 1, vector<bool>(m + 1, false));
    while (t--)
    {
        int x, y;
        cin >> x >> y;

        g[x][y] = false;
    }

    visited[stx][sty] = true;

    dfs(stx, sty);

    cout << res << '\n';

    return 0;
}