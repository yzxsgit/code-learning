#include <iostream>
#include <unordered_map>

using namespace std;

const int mod = 9901;
unordered_map<int, int> primes;

int a, b;

void primes_divide(int x)
{
    for (int i = 2; i <= x / i; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            primes[i % mod] += b;
        }
    }
    if (x > 1)
        primes[x % mod] += b;
}

int qmi(int x, int y, int p)
{
    int res = 1;
    while (y)
    {
        if (y & 1)
            res = res * x % p;
        x = x * x % mod;
        y >>= 1;
    }

    return res;
}

int sum(int p, int c)
{
    if(c == 0)
        return 1;
    else if (c & 1)
        return (1 + qmi(p, (c + 1) / 2, mod)) * sum(p, (c - 1) / 2) % mod;
    else
        return ((1 + qmi(p, c / 2, mod)) * sum(p, c / 2 - 1) + qmi(p, c, mod)) % mod;
}

int main()
{
    scanf("%d%d", &a, &b);
    
    primes_divide(a);

    int res = 1;

    for (auto prime : primes)
    {

        int p = prime.first, c = prime.second;
        res = res * sum(p, c) % mod;
    }
    if (a == 0)
        cout << 0 << endl;
    else
        cout << res << endl;

    return 0;
}