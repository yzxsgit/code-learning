#include <iostream>
#include <iomanip>

using namespace std;
const int N = 3e3 + 10;
double f[N][N];
int n;
double p;
int main()
{
    cin >> n;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        f[i][0] = f[i - 1][0] * (1 - p);
        for (int j = 1; j <= i; j++)
        {
            f[i][j] = f[i - 1][j - 1] * p + f[i - 1][j] * (1 - p);
        }
    }
    double ans = 0;
    for (int i = n / 2 + 1; i <= n; i++)
        ans += f[n][i];
    // ans /= n;

    cout << fixed << setprecision(10) << ans << endl;
    // for (int i = 1; i <= n; i++)
    // {
    //     for (int j = 0; j <= i; j++)
    //         cout << f[i][j] << " ";
    //     cout << endl;
    // }
    return 0;
}