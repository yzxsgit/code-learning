#include <iostream>

using namespace std;
const int M = 1010;
int f[M][M];
int n, m, x;
int main()
{
    cin >> n >> m >> x;
    for (int i = 0; i < n; i++)
    {
        int v, w1, w2;
        cin >> v >> w1 >> w2;
        for (int j = m; j >= w1; j--)
            for (int k = x; k >= w2; k--)
                f[j][k] = max(f[j][k], f[j - w1][k - w2] + v);
    }

    cout << f[m][x] << "\n";

    return 0;
}