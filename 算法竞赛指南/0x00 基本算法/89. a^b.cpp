#include <iostream>

using namespace std;

long long pmi(int a,int b,int p)
{
    long long res = 1 % p;
    while (b)
    {
        if(b & 1)
            res = (long long)res * a % p;
        a = (long long)a * a % p;
        b >>= 1;
    }

    return res;
}

int main()
{
    int a, b, p;
    cin >> a >> b >> p;
    
    printf("%lld", pmi(a, b, p));

    return 0;
}