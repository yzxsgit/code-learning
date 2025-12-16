#include <bits/stdc++.h>
using namespace std;
const int N = 1010, mod = 1e9 + 7;
int f[N];
int main()
{
    int n;
    cin >> n;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = i; j <= n; j++)
            f[j] = (f[j] + f[j - i]) % mod;

    printf("%d\n", f[n]);

    return 0;
}