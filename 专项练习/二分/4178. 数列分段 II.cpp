#include <iostream>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N];

bool check(int x)
{
    int res = 0, sum = 0;
    for (int i = 0; i < n; i++)
    {
        if(sum + a[i] <= x)
            sum += a[i];
        else
        {
            sum = a[i];
            res++;
        }
    }

    return res < m;

}

int bsearch(int l, int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}

int main()
{
    scanf("%d%d", &n, &m);
    int r = 0,l = 0;
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
        l = max(l, a[i]);
        r += a[i];
    }
    int ans = bsearch(l, r);
    printf("%d\n", ans);

    return 0;
}