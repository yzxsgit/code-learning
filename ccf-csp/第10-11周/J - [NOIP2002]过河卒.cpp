#include <iostream>

using namespace std;
const int N = 30, dx[8] = {-2, -2, -1, -1, 1, 1, 2, 2}, dy[8] = {-1, 1, -2, 2, -2, 2, -1, 1};

long long f[N][N];
bool st[N][N];
int main()
{
    int n, m, x, y;
    cin >> n >> m >> x >> y;
    st[x][y] = true;
    for (int i = 0; i < 8; i++)
    {
        int nx = dx[i] + x, ny = dy[i] + y;
        if (nx >= 0 && nx <= n && ny >= 0 && ny <= m)
            st[nx][ny] = true;
    }
    f[0][0] = 1;
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
            if (!st[i][j])
            {
                if (i > 0 && j > 0)
                    f[i][j] = f[i - 1][j] + f[i][j - 1];
                else if(i > 0)
                    f[i][j] = f[i - 1][j];
                else if(j > 0)
                    f[i][j] = f[i][j - 1];
            }
    }
        
    cout << f[n][m] << "\n";
    
    return 0;
}