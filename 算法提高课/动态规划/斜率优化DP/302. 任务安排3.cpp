#include <iostream>
#include <cstring>

using namespace std;
const int N = 3e5 + 10;
typedef long long ll;

ll f[N];
ll c[N], t[N];
int n, q[N];
int S;

int main()
{
    scanf("%d%d", &n, &S);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &t[i], &c[i]);
        t[i] += t[i - 1];
        c[i] += c[i - 1];
    }

    int hh = 0, tt = 0;
    q[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        ll k = t[i] + S;
        int l = hh, r = tt;
        while (l < r)
        {
            int mid = l + r >> 1;
            ll x1 = c[q[mid]], y1 = f[q[mid]];
            ll x2 = c[q[mid + 1]], y2 = f[q[mid + 1]];
            if ((y2 - y1) > k * (x2 - x1))
                r = mid;
            else
                l = mid + 1;
        }

        int j = q[r];
        f[i] = f[j] - k * c[j] + t[i] * c[i] + S * c[n];
        ll x = c[i], y = f[i];
        while (hh < tt)
        {
            ll x1 = c[q[tt]], y1 = f[q[tt]];
            ll x2 = c[q[tt - 1]], y2 = f[q[tt - 1]];
            if ((__int128)(y - y1) * (x1 - x2) <= (__int128)(y1 - y2) * (x - x1))
                tt--;
            else
                break;
        }
        q[++tt] = i;
    }

    printf("%lld\n", f[n]);

    return 0;
}