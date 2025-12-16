#include <iostream>

using namespace std;
const int N = 3e5 + 10;
int a[N];
long long res;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        scanf("%d%d", &n, &k);
        long long sub = 1e14;
        res = 0;
        for (int i = 1; i <= n; i++)
        {
            scanf("%ld", &a[i]);
            if (a[i] > 0)
                res += a[i];
        }
        printf("%lld\n", res);
    }

    return 0;
}