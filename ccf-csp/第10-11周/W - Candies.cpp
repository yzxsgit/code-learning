#include <iostream>
#include <algorithm>
using namespace std;

const int N = 110, M = 1e5 + 10, mod = 1e9 + 7;

int f[M], s[M];
int n, K;
int a[N];

int main()
{
    cin >> n >> K;
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    f[0] = 1;
    for (int j = 0; j <= K; j++)
        s[j] = 1;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= K; j++)
        {
            int mn = min(a[i], j);
            if (j - mn - 1 < 0)
                f[j] = s[j] % mod;
            else
                f[j] = (s[j] - s[j - mn - 1] + mod) % mod;
        }
        s[0] = f[0];
        for (int j = 1; j <= K; j++)
            s[j] = (s[j - 1] + f[j]) % mod;
    }

    cout << f[K] << endl;
    return 0;
}