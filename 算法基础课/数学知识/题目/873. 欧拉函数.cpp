#include <bits/stdc++.h>
using namespace std;
int phi (int x)
{
    int res = x;
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            res = res / i * (i - 1);
            while (x % i == 0)
                x /= i;
        }
    }
    if (x > 1)
        res = res / x * (x - 1);
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a;
        scanf("%d", &a);
        printf("%d\n", phi(a));
    }

    return 0;
}