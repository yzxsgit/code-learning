#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int N = 110, dx[8] = {-2, -1, 1, 2, 2, 1, -1, -2}, dy[8] = {-1, -2, -2, -1, 1, 2, 2, 1};

int f[N][N];
int n, k;
int res = 1;

bool check(int t)
{
    if (t > 0 && t <= n)
        return true;
    else
        return false;
}

void bfs(int x, int y)
{
    queue<pair<int, int>> q;
    q.push({x, y});
    f[x][y] = 0;
    while (q.size())
    {
        auto t = q.front();
        q.pop();
        int tx = t.first, ty = t.second;
        for (int i = 0; i < 8; i++)
        {
            int nx = tx + dx[i], ny = ty + dy[i];
            if (check(nx) && check(ny))
            {
                if(f[nx][ny] == -1 && f[tx][ty] < k)
                {
                    f[nx][ny] = f[tx][ty] + 1;
                    q.push({nx, ny});
                    res++;
                }
            }
        }
    }
}

int main()
{
    memset(f, -1, sizeof f);
    cin >> n >> k;
    int x, y;
    cin >> x >> y;
    bfs(x, y);
    cout << res << endl;
    cout << "\n";
    return 0;
}