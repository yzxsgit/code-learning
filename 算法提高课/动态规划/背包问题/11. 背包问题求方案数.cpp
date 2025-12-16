#include <iostream>
#include <cstring>

using namespace std;

const int N = 1010, mod = 1e9 + 7;
int n, m;
int f[N], g[N];

int main()
{
    cin >> n >> m;
    memset(f, -0x3f, sizeof f);
    f[0] = 0;
    g[0] = 1;
    for (int i = 0; i < n; i++)
    {
        int v, w;
        cin >> v >> w;

        for (int j = m; j >= v; j--)
        {
            int maxv = max(f[j], f[j - v] + w);
            int s = 0;
            if(maxv == f[j])
                s = g[j];
            if (maxv == f[j - v] + w)
                s = (s + g[j - v]) % mod;
            f[j] = maxv, g[j] = s;
        }
    }

    int res = 0;
    for (int i = 1; i <= m; i++)
        if(f[i] > f[res])
            res = i;

    int sum = 0;
    for (int i = 0; i <= m; i++)
        if(f[i] == f[res])
            sum = (sum + g[i]) % mod;

    cout << sum << "\n";

    return 0;
}