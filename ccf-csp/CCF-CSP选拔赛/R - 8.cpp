#include <iostream>

using namespace std;
const int N = 2e5 + 10;
int a[N];
int n;
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
            scanf("%d", &a[i]);
        int res = 0;
        int tmp = 0;
        for (int i = 0; i < n; i++)
        {
            if(tmp > a[i])
                res = max(a[i] + tmp, res);
            else
                tmp = a[i];
        }

        printf("%d\n", res);
    }
    return 0;
}