#include <iostream>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        ll a = 0, c = 0;
        ll x;
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &x);
            a += x;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &x);
            c -= x;
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%lld", &x);
            c += x;
        }
        printf("%d\n", c / a);
    }

    return 0;
}