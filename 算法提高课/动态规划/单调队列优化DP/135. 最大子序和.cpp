#include <iostream>
#include <limits.h>

using namespace std;
const int N = 3e5 + 10;

int s[N], q[N];
int res = INT_MIN;
int n, m;

int main()
{
    scanf("%d%d", &n, &m);

    for (int i = 1; i <= n; i++)
    {
        scanf("%d", &s[i]);
        s[i] += s[i - 1];
    }

    int hh = 0, tt = 0;
    for (int i = 1; i <= n; i++)
    {
        if(i - q[hh] > m)
            hh++;
        res = max(res, s[i] - s[q[hh]]);
        while (hh <= tt && s[i] <= s[q[tt]])
            tt--;
        q[++tt] = i;
    }

    printf("%d\n", res);

    return 0;
}