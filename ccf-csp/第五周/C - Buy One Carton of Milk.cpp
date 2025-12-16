#include <iostream>

using namespace std;

int n, s, m, l;
int k;

int main()
{
    scanf("%d%d%d%d", &n, &s, &m, &l);

    int ans = 0x3f3f3f3f;
    for (int i = 0; i <= n / 6 + 1; i++)
        for (int j = 0; j <= n / 8 + 1; j++)
            for (int k = 0; k <= n / 12 + 1; k++)
                if (i * 6 + j * 8 + k * 12 >= n)
                    ans = min(ans, i * s + j * m + k * l);

    printf("%d\n", ans);

    return 0;
}