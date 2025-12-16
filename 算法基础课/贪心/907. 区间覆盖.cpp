#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;

struct Range{
    int l, r;
} range[N];

bool cmp(Range a,Range b)
{
    return a.l < b.l;
}

int n, st, ed;

int main()
{
    scanf("%d%d%d", &st, &ed, &n);

    for (int i = 0; i < n; i++)
    {
        auto &r = range[i];
        scanf("%d%d", &r.l, &r.r);
    }

    sort(range, range + n, cmp);

    int ans = 0;
    bool flag = false;
    for (int i = 0; i < n; i++)
    {
        int j = i, r = -2e9;
        while (j < n && range[j].l <= st)
        {
            r = max(r, range[j].r);
            j++;
        }

        if(r < st)
        {
            ans = -1;
            break;
        }

        ans++;
        if (r >= ed)
        {
            flag = true;
            break;
        }

        st = r;
        i = j - 1;
    }

    if(!flag)
        ans = -1;
    printf("%d\n", ans);

    return 0;
}