#include <bits/stdc++.h>
using namespace std;
long long pmi(int a,int b,int p)
{
    long long res = 1 % p;
    while (b)
    {
        if(b & 1)
            res = res * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }
    return res;
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a, b, p;
        scanf("%d%d%d", &a, &b, &p);
        printf("%lld\n", pmi(a, b, p));
    }
    return 0;
}