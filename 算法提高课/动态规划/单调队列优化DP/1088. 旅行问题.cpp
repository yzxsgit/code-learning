#include <iostream>

using namespace std;
const int N = 2e6 + 10;

int p[N], d[N], q[N];
long long s[N];
int n;
bool ans[N];

int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d %d", &p[i], &d[i]);

    for (int i = 1; i <= n; i++)
        s[i] = s[i + n] = p[i] - d[i];
    for (int i = 1; i <= n * 2; i++)
        s[i] += s[i - 1];

    q[0] = n * 2 + 1;
    int hh = 0, tt = 0;
    for (int i = 2 * n; i >= 0; i--)
    {
        if(q[hh] - i > n)
            hh++;
        if (i < n)
        {
            if(s[i] <= s[q[hh]])
                ans[i + 1] = true;
        }
        while (hh <= tt && s[q[tt]] >= s[i])
            tt--;
        q[++tt] = i;
    }

    d[0] = d[n];
    for (int i = 1; i <= n; i++)
        s[i] = s[i + n] = p[i] - d[i - 1];
    for (int i = 1; i <= n * 2; i++)
        s[i] += s[i - 1];

    q[0] = 0;
    hh = 0, tt = 0;
    for (int i = 1; i <= n * 2; i++)
    {
        if(q[hh] + n < i)
            hh++;
        if (i > n)
        {
            if(s[i] >= s[q[hh]])
                ans[i - n] = true;
        }
        while (hh <= tt && s[q[tt]] <= s[i])
            tt--;
        q[++tt] = i;
    }

    for (int i = 1; i <= n; i++)
        puts(ans[i] ? "TAK" : "NIE");

    return 0;
}