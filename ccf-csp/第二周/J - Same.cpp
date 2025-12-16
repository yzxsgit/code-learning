#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    n--;
    int a, b;
    scanf("%d", &a);
    while (n--)
    {
        scanf("%d", &b);
        if(a != b)
        {
            printf("No");
            return 0;
        }
    }
    printf("Yes");
    return 0;
}