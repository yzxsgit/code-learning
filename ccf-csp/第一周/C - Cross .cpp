#include <bits/stdc++.h>
using namespace std;
const int N = 110, fx[4] = {-1, -1, 1, 1}, fy[4] = {-1, 1, -1, 1};
char a[N][N];
int s[N];
bool st[N][N];
int h, w;
int find(int x, int y)
{
    int d = 1;
    bool flag = true;
    while (flag)
    {
        for (int i = 0; i < 4; i++)
        {
            int nx = x + fx[i] * d, ny = y + fy[i] * d;
            if (nx >= 0 && nx <= h && ny >= 0 && ny <= w && st[nx][ny])
                continue;
            else
            {
                flag = false;
            }
        }
        if (flag)
            d++;
    }
    d--;
    if(d)
        for (int i = 0; i <= d; i++)
        {
            for (int j = 0; j <= 3; j++)
            {
                int nx = x + fx[j] * i, ny = y + fy[j] * i;
                st[nx][ny] = false;
            }
        }

    return d;
}
int main()
{
    scanf("%d%d", &h, &w);
    for (int i = 0; i <= h; i++)
    {
        scanf("%s", a[i]);
        for (int j = 0; j < w; j++)
            if (a[i][j] == '#')
                st[i][j] = true;
    }
    for (int i = 0; i <= h; i++)
        for (int j = 0; j <= w; j++)
            if (st[i][j])
            {
                int ans = find(i, j);
                if (ans)
                {
                    s[ans]++;
                }
            }

    int n = min(w, h);

    for (int i = 1; i <= n; i++)
        printf("%d ", s[i]);
}