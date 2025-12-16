#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n, a, b;
    scanf("%d%d%d", &n, &a, &b);
    for (int i = 1; i <= n;i++)
    {
        int ans;
        scanf("%d", &ans);
        if(ans == a + b)
            printf("%d", i);
    }
    return 0;
}