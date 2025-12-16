#include <iostream>
#include <cstring>

using namespace std;
const int N = 410;
long long s[N], f[N][N];
int a[N];
int n;

int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + a[i];
    
    memset(f, 0x3f, sizeof f);

    for (int len = 1; len <= n; len++)
        for (int i = 1; i + len - 1 <= n; i++)
        {
            int j = i + len - 1;
            if(len == 1)
            {
                f[i][j] = 0;
                continue;
            }

            for (int k = i; k <= j - 1; k++)
                f[i][j] = min(f[i][j], f[i][k] + f[k + 1][j] + s[j] - s[i - 1]);
        }

    cout << f[1][n] << "\n";

    return 0;
}