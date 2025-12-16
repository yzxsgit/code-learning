#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 10;
int a[N];
int n, m;

int main()
{
    scanf("%d%d",&n,&m);
    for (int i = 1; i <= m; i++)
        scanf("%d", &a[i]);
    int i = 1;
    int j = 1;
    while (i <= m && j <= n)
    {
        if(j == a[i])
        {
            puts("0");
            i++;
            j++;
        }
        else if(j < a[i])
        {
            printf("%d\n",a[i] - j);
            j++;
        }
    }

    return 0;
}