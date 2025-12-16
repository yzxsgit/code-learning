#include <iostream>

using namespace std;
const int N = 3e3 + 10;
int a[N], b[N];
int f[N][N];
int n;

int main()
{
    scanf("%d", &n);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    for (int i = 1; i <= n; i++)
        scanf("%d", &b[i]);

    for (int i = 1; i <= n; i++)
    {
        int maxv = 1;
        for (int j = 1; j <= n; j++)
        {
            f[i][j] = f[i - 1][j];
            if(a[i] == b[j])
                f[i][j] = max(f[i][j], maxv);
            if(b[j] < a[i])
                maxv = max(f[i][j] + 1, maxv);
        }
    }
    int res = 0;
    for (int j = 1; j <= n; j++)
        res = max(f[n][j], res);

    printf("%d\n",res);

    return 0;
}