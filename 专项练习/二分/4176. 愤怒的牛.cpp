#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N];

bool check(int x)
{
    int res = a[0], cnt = 1;
    for (int i = 1; i < n; i++)
    {
        if(a[i]-res>=x)
        {
            cnt++;
            res = a[i];
        }
    }

    return cnt >= m;
}
int bsearch(int l,int r)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            l = mid + 1;
        else
            r = mid;
    }
    
    return l - 1;
}
int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    sort(a, a + n);
    int ans = bsearch(1, a[n - 1] - a[0]);

    printf("%d\n", ans);

    return 0;
}