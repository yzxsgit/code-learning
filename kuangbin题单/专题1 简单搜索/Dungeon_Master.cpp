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
using PII = pair<int, int>;

vector<vector<vector<char>>> g;

int l, r, c;

struct Dot
{
    int x, y, z;
    bool operator==(const Dot &t) const
    {
        return x == t.x && y == t.y && z == t.z;
    }
};

int bfs(Dot s, Dot e)
{
    int dx[] = {1, -1, 0, 0, 0, 0}, dy[] = {0, 0, 1, -1, 0, 0}, dz[] = {0, 0, 0, 0, 1, -1};

    vector<vector<vector<bool>>> st(l, vector<vector<bool>>(r, vector<bool>(c, false)));
    queue<pair<int, Dot>> q;

    q.push({0, s});
    st[s.x][s.y][s.z] = true;

    while (!q.empty())
    {
        pair<int, Dot> t = q.front();
        q.pop();
        int dist = t.first;
        Dot u = t.second;
        if (u == e)
            return dist;
        for (int i = 0; i < 6; i++)
        {
            int nx = u.x + dx[i], ny = u.y + dy[i], nz = u.z + dz[i];
            if (nx < 0 || ny < 0 || nz < 0 || nx >= l || ny >= r || nz >= c)
                continue;
            if (!st[nx][ny][nz] && g[nx][ny][nz] != '#')
            {
                st[nx][ny][nz] = true;
                q.push({dist + 1, {nx, ny, nz}});
            }
        }
    }

    return -1;
}

void solve()
{
    Dot st, ed;

    g.resize(l, vector<vector<char>>(r, vector<char>(c)));

    for (int i = 0; i < l; i++)
    {
        for (int j = 0; j < r; j++)
        {
            for (int k = 0; k < c; k++)
            {
                cin >> g[i][j][k];
                if (g[i][j][k] == 'S')
                    st = {i, j, k};
                if (g[i][j][k] == 'E')
                    ed = {i, j, k};
            }
        }
    }
    int res = bfs(st, ed);
    if (res != -1)
    {
        cout << "Escaped in " << res << " minute(s).\n";
    }
    else
    {
        cout << "Trapped!\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    while (cin >> l >> r >> c, l || r || c)
    {
        solve();
    }
    return 0;
}