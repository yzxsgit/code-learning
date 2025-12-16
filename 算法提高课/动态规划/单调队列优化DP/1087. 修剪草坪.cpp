#include <iostream>
#include <limits.h>

using namespace std;
const int N = 1e6 + 10;

int n, m;
long long f[N];
int e[N], q[N];
long long res;

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &e[i]);
        res += e[i];
    }

    int hh = 0, tt = 0;
    q[0] = 0;
    f[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        if (q[hh] < i - m - 1)
            hh++;
        f[i] = f[q[hh]] + e[i];
        while (hh <= tt && f[q[tt]] >= f[i])
            tt--;
        q[++tt] = i;
    }
    // for (int i = 1; i <= n; i++)
    //     cout << f[i] << " ";
    // cout << "\n";
    long long tmp = LONG_LONG_MAX;
    for (int i = n - m; i <= n; i++)
        tmp = min(f[i], tmp);

    cout << res - tmp << endl;

    return 0;
}