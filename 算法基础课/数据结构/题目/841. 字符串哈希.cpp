#include <bits/stdc++.h>
using namespace std;
const int P = 131, N = 1e5 + 3;
unsigned long long h[N], p[N];
char str[N];
unsigned long long get(int l, int r)
{
    return h[r] - h[l - 1] * p[r - l + 1];
}
int main()
{
    int n, m;
    scanf("%d%d%s", &n, &m, str + 1);

    p[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        p[i] = p[i - 1] * P;
        h[i] = h[i - 1] * P + str[i];
    }
    while (m--)
    {
        int l1, l2, r1, r2;
        scanf("%d%d%d%d", &l1, &r1, &l2, &r2);

        if (get(l1, r1) == get(l2, r2))
            printf("Yes\n");
        else
            printf("No\n");
    }
    return 0;
}