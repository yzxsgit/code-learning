#include <iostream>
#include <cstring>

using namespace std;

const int dx[5] = {-1, 0, 1, 0, 0}, dy[5] = {0, 1, 0, -1, 0};

bool g[7][7], back_up[7][7];

void turn(int x, int y)
{
    for (int i = 0; i < 5; i++)
    {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx >= 0 && nx <= 4 && ny >= 0 && ny <= 4)
            g[nx][ny] ^= 1;
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    getchar();
    while (n--)
    {
        char ch;
        for (int i = 0; i < 5; i++)
        {
            for (int j = 0; j < 5; j++)
            {
                ch = getchar();
                g[i][j] = ch - 48;
            }
            getchar();
        }
        getchar();
        int ans = 100000;

        memcpy(back_up, g, sizeof g);
        for (int i = 0; i < 1 << 5; i++)
        {
            int op = 0;
            for (int j = 0; j < 5; j++)
                if (i >> j & 1)
                {
                    op++;
                    turn(0, j);
                }

            for (int j = 0; j < 4; j++)
                for (int k = 0; k <= 4; k++)
                    if (!g[j][k])
                    {
                        op++;
                        turn(j + 1, k);
                    }

            bool flag = true;
            for (int j = 0; j <= 4; j++)
                if (!g[4][j])
                    flag = false;

            if (flag)
                ans = min(ans, op);

            memcpy(g, back_up, sizeof g);
        }

        if (ans > 6)
            printf("-1\n");
        else
            printf("%d\n", ans);
    }

    return 0;
}