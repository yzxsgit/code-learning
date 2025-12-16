#include <bits/stdc++.h>
using namespace std;

int l, r ,a ,n;
int main()
{

    scanf("%d%d%d", &n, &l, &r);

    while (n--)
    {
        scanf("%d", &a);

        if(a < l)
            printf("%d ", l);
        else if (a > r)
            printf("%d ", r);
        else
            printf("%d ", a);
    }

    return 0;
}