#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 10, dx[8] = {-1, 0, 1, 0, -1, -1, 1, 1}, dy[8] = {0, 1, 0, -1, -1, 1, -1, 1};
char s[N][N];
int n;

bool check(int x, int y)
{
    bool flag = false;
    for (int t = 0; t < 8; t++)
    {
        if (dx[t] * 5 + x >= 0 && dx[t] * 5 + x < n && dy[t] * 5 + y >= 0 && dy[t] * 5 + y < n)
        {
            int res = 0;
            for (int i = 1; i <= 5; i++)
            {
                int new_x = dx[t] * i + x, new_y = dy[t] * i + y;
                if (s[new_x][new_y] == '.')
                    res++;
            }
            if (res <= 2)
            {
                flag = true;
                break;
            }
        }
    }

    return flag;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
        scanf("%s", s[i]);

    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (s[i][j] == '#' && check(i, j))
            {
                flag = true;
                break;
            }
        }
        if (flag)
            break;
    }

    if (flag)
        puts("Yes");
    else
        puts("No");

    return 0;
}