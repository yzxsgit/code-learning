#include <bits/stdc++.h>
using namespace std;
void divide(int x)
{
    for (int i = 2; i <= x / i; i++)
    {
        if (x % i == 0)
        {
            int cnt = 0;
            while (x % i == 0)
            {
                x /= i;
                cnt++;
            }
            printf("%d %d\n", i, cnt);
        }
    }

    if (x > 1)
        printf("%d 1\n", x);

    return;
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int x;
        scanf("%d", &x);
        divide(x);
     
       printf("\n");
    }

    return 0;
}