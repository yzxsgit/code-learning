#include <iostream>
#include <cstring>

using namespace std;
const int N = 90, M = 22;
int f[M][N];
int n, m, t;

int main()
{
    cin >> m >> n;
    cin >> t;
    
    memset(f, 0x3f, sizeof f);
    f[0][0] = 0;

    for (int i = 1; i <= t; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        for (int j = m; j >= 0; j--)
            for (int k = n; k >= 0; k--)
                f[j][k] = min(f[j][k], f[max(0, j - a)][max(0, k - b)] + w);
    }

    cout << f[m][n] << '\n';

    return 0;
}