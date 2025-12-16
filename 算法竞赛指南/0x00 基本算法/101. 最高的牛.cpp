#include <iostream>

using namespace std;

const int N = 5010;
bool g[N][N];
int height[N];
int n, p, h, m;

int main()
{
    scanf("%d%d%d%d", &n, &p, &h, &m);
    while (m--)
    {
        int x, y;
        scanf("%d%d", &x, &y);
        if(x > y)
            swap(x, y);
        if(!g[x][y])
        {
            height[x + 1] -= 1;
            height[y] += 1;
            g[x][y] = true;
        }
        g[x][y] = true;
    }
    height[0] = h;
    for (int i = 1; i <= n; i++)
        height[i] += height[i - 1];

    for (int i = 1; i <= n; i++)
        printf("%d\n",height[i]);

    return 0;
}