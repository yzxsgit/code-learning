#include <iostream>

using namespace std;

long long qm(long long a,long long b,long long p)
{
    long long res = 0;
    while (b)
    {
        if(b & 1)
            res = (res + a) % p;
        a = (a << 1) % p;
        b >>= 1;
    }

    return res;
}

int main()
{
    long long a, b, p;
    cin >> a >> b >> p;

    printf("%lld", qm(a, b, p));

    return 0;
}