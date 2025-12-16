#include <bits/stdc++.h>
using namespace std;
const int N = 1e4 + 10;
int A[N], B[N];
int bound(int l, int r, int a)
{
    while (l < r)
    {
        int mid = l + r >> 1;
        if (B[mid] >= a)
            r = mid;
        else
            l = mid + 1;
        // printf("%d ", mid);
    }
    // puts("");

    return l;
}
int main()
{
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &B[i]);

    sort(B, B + n);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        int a = A[i];
        int MIN = 0x3f3f3f3f;

        int it = bound(0, n - 1, a);
        // printf("%d %d\n",a, it);
        if (it != n)
            MIN = min(MIN, abs(B[it] - a));
        if (it != 0)
            MIN = min(MIN, abs(B[it - 1] - a));

        ans = max(MIN, ans);
    }

    printf("%d\n", ans);

    return 0;
}