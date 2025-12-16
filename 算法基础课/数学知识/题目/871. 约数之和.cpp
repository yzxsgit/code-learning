#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
unordered_map<int, int> primes;
void primes_divide(int x)
{
    for (int i = 2; i <= x / i ; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            primes[i]++;
        }
    }
    if (x > 1)
        primes[x]++;

}
int main()
{
    int n;
    scanf("%d", &n);
    while(n--)
    {
        int a;
        scanf("%d", &a);
        primes_divide(a);
    }
    long long res = 1;

    for (auto p : primes)
    {
        long long x = p.first, y = p.second;
        long long t = 1;
        while(y--)
            t = (t * x + 1) % mod;
        res = res * t % mod;
    }

    printf("%d\n", res);
    
    return 0;
}