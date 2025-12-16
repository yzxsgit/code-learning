#include <iostream>
#include <cstring>

using namespace std;
const int N = 110, dx[3] = {0, 1, 1}, dy[3] = {1, 0, 1};
char g[N][N];
int n;
bool dg[N * 2], udg[N * 2], x[N], y[N];
bool check(int x,int y)
{
    for (int i = 0; i < 3; i++)
    {
        int nx = dx[i] + x, ny = dy[i] + y;
        if (nx >= n || ny >= n)
            return false;
        else if (g[nx][ny] == '.')
            return false;
    }
    return true;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        memset(dg, 0, sizeof dg);
        memset(udg, 0, sizeof udg);
        memset(x, 0, sizeof x);
        memset(y, 0, sizeof y);
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%s", g[i]);
        int num = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if(g[i][j] == '#')
                {
                    dg[i + j] = true;
                    udg[n - j + i - 1] = true;
                    x[i] = true;
                    y[j] = true;
                    num++;
                }

        bool flag = false;
        int count_dg = 0, count_udg = 0,count_x = 0,count_y = 0;
        int begin_dg, begin_udg;
        for (int i = 0; i <= n * 2; i++)
        {
            if(dg[i])
                count_dg++,begin_dg = i;
            if(udg[i])
                count_udg++,begin_udg = i;
        }
        for (int i = 0; i < n; i++)
        {
            if(y[i])
                count_y++;
            if(x[i])
                count_x++;
        }
        if(count_dg <= 2)
        {
            if(count_dg <= 1)
                flag = true;
            else if(begin_dg - 1 >= 0 && dg[begin_dg - 1] || begin_dg + 1 < n && dg[begin_dg + 1])
                    flag = true;
        }
        if (count_udg <= 2)
        {
            if (count_udg <= 1)
                flag = true;
            else if (begin_udg - 1 >= 0 && udg[begin_udg - 1] || begin_udg + 1 < n && udg[begin_udg + 1])
                flag = true;
        }
        if (!flag && num == 4 && count_x == 2 && count_y == 2)
        {
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                    if(g[i][j] == '#')
                    {
                        flag = check(i, j);
                        if(flag)
                            break;
                    }
                if(flag)
                    break;
            }
        }
        // cout << count_dg << " " << count_udg << " " << count_x << " " << count_y << endl;
        cout << (flag ? "YES" : "NO") << "\n";
    }
    
    return 0;
}