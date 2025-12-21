#include <iostream>

using namespace std;
const int N = 5e3 + 10;

int v[N];
long long f[N][N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> v[i];

    for (int len = 1; len <= n; len++)
        for (int l = 1; l <= n - len + 1; l++)
        {
            int r = l + len - 1;
            int k = n - len + 1;

            f[l][r] = max(f[l + 1][r] + v[l] * k, f[l][r - 1] + v[r] * k);
        }

    cout << f[1][n] << "\n";

    return 0;
}