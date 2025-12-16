#include <bits/stdc++.h>
using namespace std;

const int N = 1e6 + 10, mod = 100003;
int f[N];
int n, k;

int main()
{
    cin >> n >> k;

    f[0] = f[1] = 1;
    for (int i = 2; i <= n; i++)
        for (int j = 1; j <= min(k, i); j++)
            f[i] = (f[i] + f[i - j]) % mod;

    cout << f[n] <<endl;

    return 0;
}
