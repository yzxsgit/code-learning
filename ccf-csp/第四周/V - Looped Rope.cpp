#include <bits/stdc++.h>
using namespace std;

const int N = 21, dx[4] = {-1, 0, 1, 0}, dy[4] = {0, 1, 0, -1};
char s[N][N];
int h, w;

int main()
{
    scanf("%d%d", &h, &w);
    for (int i = 0; i < h; i++)
        scanf("%s", s[i]);
    bool flag = true;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < w; j++)
            if (s[i][j] == '#')
            {
                int res = 0;
                for (int k = 0; k < 4; k++)
                {
                    int new_x = dx[k] + i, new_y = dy[k] + j;
                    if (new_x >= 0 && new_x < h && new_y >= 0 && new_y < w && s[new_x][new_y] == '#')
                        res++;
                }
                if (res != 2 && res != 4)
                {
                    flag = false;
                    break;
                }
            }
        if (!flag)
            break;
    }

    if (flag)
        puts("Yes");
    else
        puts("No");

    return 0;
}