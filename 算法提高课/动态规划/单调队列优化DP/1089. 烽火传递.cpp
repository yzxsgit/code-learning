#include <iostream>

using namespace std;
const int N = 2e5 + 10;

int f[N], w[N], q[N];
int n, m;
int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
        scanf("%d", &w[i]);

    int hh = 0, tt = 0;
    f[0] = q[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        if(q[hh] < i - m)
            hh++;
        f[i] = f[q[hh]] + w[i];
        while (hh <= tt && f[q[tt]] >= f[i])
            tt--;
        q[++tt] = i;
    }

    int res = 1e9;
    for (int i = n - m + 1; i <= n; i++)
        res = min(res, f[i]);

    cout << res << endl;

    return 0;
}