#include <bits/stdc++.h>
using namespace std;
long long qmi(int a,int k,int m)
{
    long long res = 1 % m;
    while(k)
    {
        if(k & 1)
            res = res * a % m;
        a = (long long)a * a % m;
        k >>= 1;
    }
    return res;
}

int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a, p;
        scanf("%d%d", &a, &p);
        if (a % p == 0)
            puts("impossible");
        else
            printf("%lld\n", qmi(a, p - 2, p));
    }
    return 0;
}
