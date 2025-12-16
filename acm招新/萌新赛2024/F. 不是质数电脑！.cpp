#include <iostream>

using namespace std;
const int mod = 114;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int res = 0;
        while (n--)
        {
            int x;
            scanf("%d",&x);
            res = res + x % mod;
        }

        printf("%d\n", res);
    }
}