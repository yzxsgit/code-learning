#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int N = 1e5 + 10;
int n, x;
long long s;
int a[N];
int out[N];

bool check(int u)
{
    return (s + a[u]) / x == s / x;
}

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        s = 0;
        scanf("%d%d", &n, &x);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        long long res = 0;
        sort(a, a + n);
        int i = 0, j = n - 1, idx = 0;
        while (i <= j)
        {
            if (!check(j))
            {
                s += a[j];
                res += a[j];
                out[idx++] = a[j];
                j--;
            }
            else
            {
                s += a[i];
                out[idx++] = a[i];
                i++;
            }
            // printf("%d\n", s);
        }
        printf("%lld\n", res);
        for (int i = 0; i < n; i++)
            printf("%d ", out[i]);
        printf("\n");
    }
    return 0;
}