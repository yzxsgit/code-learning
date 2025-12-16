#include <bits/stdc++.h>
using namespace std;
const int N = 110, mod = 1e9 + 7;
unordered_map<int, int> primes;
void primes_divide(int x)
{
    for (int i = 2; i <= x / i; i++)
    {
        while (x % i == 0)
        {
            x /= i;
            primes[i] ++;
        }
    }
    if(x > 1)
        primes[x]++;
}
int main()
{
    int n;
    scanf("%d", &n);
    while (n--)
    {
        int a;
        scanf("%d", &a);
        primes_divide(a);
    }
    long long res = 1;
    for (auto i : primes)
        res = res * (i.second + 1) % mod;

    printf("%d\n", res);
    
    return 0;
}