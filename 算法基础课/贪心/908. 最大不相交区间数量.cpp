#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10, INF = 0x3f3f3f3f;

struct Range{
    int l, r;
} range[N];

bool cmp(Range a,Range b)
{
    return a.r < b.r;
}

int n;

int main()
{
    scanf("%d", &n);

    for (int i = 0; i < n; i++)
        scanf("%d%d", &range[i].l, &range[i].r);

    sort(range, range + n, cmp);

    int ans = 0, p = -INF;

    for (int i = 0; i < n; i++)
    {
        Range r = range[i];
        if(p >= r.l)
            p = min(p, r.r);
        else
        {
            ans++;
            p = r.r;
        }
    }

    printf("%d\n", ans);

    return 0;
}