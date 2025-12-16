#include <iostream>

using namespace std;
const int N = 1010, mod = 1e9 + 7, dx[2] = {1, 0}, dy[2] = {0, 1};
int f[N][N];
char map[N][N];
int n, m;
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            cin >> map[i][j];

    f[1][1] = 1;

    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            for (int k = 0; k <= 1; k++)
                {
                    int nx = dx[k] + i, ny = dy[k] + j;
                    if (nx > 0 && nx <= n && ny > 0 && ny <= m)
                    {
                        if(map[nx][ny]=='.')
                            f[nx][ny] = (f[nx - 1][ny] + f[nx][ny - 1]) % mod;
                    }
                }

    cout << f[n][m] << endl;

    return 0;
}