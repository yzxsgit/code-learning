#include <bits/stdc++.h>
using namespace std;
const int N = 2e3 + 10, mod = 1e9 + 7;
int c[N][N];

void init()
{
    for (int i = 0; i <= 2e3; i++)
        c[i][0] = 1;

    for (int i = 1; i <= 2e3; i++)
        for (int j = 1; j <= i; j++)
            c[i][j] = (long long)(c[i - 1][j] + c[i - 1][j - 1]) % mod;
}

int main()
{
    init();
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        printf("%d\n", c[a][b]);
    }
    return 0;
}