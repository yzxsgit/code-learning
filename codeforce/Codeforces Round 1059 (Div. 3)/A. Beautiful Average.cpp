#include <iostream>

using namespace std;

int main()
{
    int t;
    scanf("%d",&t);
    while (t--)
    {
        int res = 0, a, n;
        scanf("%d", &n);
        while(n--)
        {
            scanf("%d",&a);
            res = max(res, a);
        }

        printf("%d\n", res);
    }

    return 0;
}