#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;
const int N = 1e5 + 10, P = 110;

int n, m, p;
ll d[N], t[N], a[N], s[N];
ll f[P][N];
int q[N];

ll get_y(int k,int j)
{
    return f[j - 1][k] + s[k];
}

int main()
{
    scanf("%d%d%d", &n, &m, &p);
    for (int i = 2; i <= n; i++)
    {
        scanf("%lld", &d[i]);
        d[i] += d[i - 1];
    }

    for (int i = 1; i <= m; i++)
    {
        int h;
        scanf("%d%lld", &h, &t[i]);
        a[i] = t[i] - d[h];
    }

    sort(a + 1, a + m + 1);

    for (int i = 1; i <= m; i++)
        s[i] = s[i - 1] + a[i];

    memset(f, 0x3f, sizeof f);
    for (int i = 0; i <= p; i++)
        f[i][0] = 0;

    for (int j = 1; j <= p; j++)
    {
        int hh = 0, tt = 0;
        q[0] = 0;

        for (int i = 1; i <= m; i++)
        {
            while (hh < tt && (get_y(q[hh + 1], j) - get_y(q[hh], j)) <= a[i] * (q[hh + 1] - q[hh]))
                hh++;
            int k = q[hh];
            f[j][i] = f[j - 1][k] - a[i] * k + s[k] + a[i] * i - s[i];
            while (hh < tt && (get_y(q[tt], j) - get_y(q[tt - 1], j)) * (i - q[tt]) >= (get_y(i, j) - get_y(q[tt], j)) * (q[tt] - q[tt - 1]))
                tt--;
            q[++tt] = i;
        }
    }

    printf("%lld\n", f[p][m]);

    return 0;
}
