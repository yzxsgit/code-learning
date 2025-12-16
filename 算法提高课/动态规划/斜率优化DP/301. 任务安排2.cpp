#include <iostream>
#include <cstring>

using namespace std;

const int N = 3e5 + 10;
typedef long long ll;
ll f[N];
ll st[N], sc[N];
int q[N], s, n;

int main()
{
    scanf("%d%d", &n, &s);
    for (int i = 1; i <= n; i++)
    {
        scanf("%lld%lld", &st[i], &sc[i]);
        st[i] += st[i - 1];
        sc[i] += sc[i - 1];
    }

    int hh = 0, tt = 0;
    q[0] = 0;
    for (int i = 1; i <= n; i++)
    {
        ll k = s + st[i];
        while (hh < tt)
        {
            ll x1 = sc[q[hh]], y1 = f[q[hh]];
            ll x2 = sc[q[hh + 1]], y2 = f[q[hh + 1]];
            if((__int128)(y2-y1)<=(__int128)(x2-x1)*k)
                hh++;
            else
                break;
        }

        int j = q[hh];
        f[i] = f[j] + s * (sc[n] - sc[j]) + (sc[i] - sc[j]) * st[i];

        ll x = sc[i], y = f[i];
        while (hh < tt)
        {
            ll x1 = sc[q[tt]], y1 = f[q[tt]];
            ll x2 = sc[q[tt - 1]], y2 = f[q[tt - 1]];
            
            if((y-y1)*(x1-x2) <= (__int128)(y1-y2)*(x-x1))
                tt--;
            else 
                break;
        }
        q[++tt] = i;
    }

    printf("%lld",f[n]);

    return 0;
}