#include <bits/stdc++.h>
using namespace std;
bool is_prime(int x)
{
    if (x < 2)
        return false;
    for (int i = 2; i <= x / i; i++)
        if(x % i == 0)
            return false;

    return true;
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a;
        scanf("%d", &a);
        if(is_prime(a))
            puts("Yes");
        else
            puts("No");
    }

    return 0;
}