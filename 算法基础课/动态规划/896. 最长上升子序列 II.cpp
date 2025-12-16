#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 10;
int a[N];
int f[N];
int n, idx;
int bsearch(int x)
{
    int l = 1, r = idx;
    while (l < r)
    {
        int mid = l + r >> 1;
        if(f[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }

    return l;
}
int main()
{
    scanf("%d", &n);

    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    f[++idx] = a[1];
    for (int i = 2; i <= n; i++)
    {
        if(f[idx] < a[i])
            f[++idx] = a[i];
        else
        {
            int x = bsearch(a[i]);
            f[x] = a[i];
        }
    }

    printf("%d\n", idx);

    return 0;
}