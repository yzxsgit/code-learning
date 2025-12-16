#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

struct fuck
{
    int idx;
    long long a, out;
} a[N];

bool cmp1(fuck x, fuck y)
{
    return x.a > y.a;
}

bool cmp2(fuck x, fuck y)
{
    return x.idx < y.idx;
}

int n;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
    {
        scanf("%lld", &a[i].a);
        a[i].idx = i;
    }

    sort(a, a + n, cmp1);

    int res = 0;
    for (int i = 1; i < n; i++)
    {
        if (a[i].a != a[res].a)
        {
            a[i].out = a[res].out + (i - res) * a[res].a;
            res = i;
        }
        else
            a[i].out = a[res].out;
    }

    sort(a, a + n, cmp2);

    for (int i = 0; i < n; i++)
        printf("%lld ", a[i].out);

    return 0;
}