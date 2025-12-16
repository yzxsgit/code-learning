#include <iostream>

using namespace std;
const int N = 1e5 + 10;
int f[N][4];
int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int w[4];
        for (int j = 1; j <= 3; j++)
            scanf("%d", &w[j]);
        for (int j = 1; j <= 3; j++)
            for (int k = 1; k <= 3; k++)
                if (j != k)
                    f[i][j] = max(f[i][j], f[i - 1][k] + w[k]);
    }

    int res = 0;
    for (int i = 1; i <= 3; i++)
        res = max(res, f[n][i]);

    cout << res << "\n";

    return 0;
}