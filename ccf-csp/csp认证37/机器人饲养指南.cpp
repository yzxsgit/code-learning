#include <iostream>
using namespace std;

const int N = 1e5 + 10, M = 110;
int a[N], n, m;
int f[M][N];
int main()
{
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
        cin >> a[i];
    for (int i = 1; i <= m; i++)
    {
        for (int j = 0; j <= n; j++)
            for (int k = 0; k <= j / i; k++)
                f[i][j] = max(f[i][j], f[i - 1][j - i * k] + (a[i] * k));
    }

    cout << f[m][n] << endl;

    return 0;
}