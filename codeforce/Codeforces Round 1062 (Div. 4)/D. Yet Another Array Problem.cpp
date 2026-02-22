#include <iostream>
#include <cstring>
#include <unordered_map>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
unordered_map<ll,int> factor;
void find_factor(ll x)
{
    for (ll i = 2; i <= x / i; i++)
    {
        while (x % i == 0)
        {
            factor[i]++;
            x /= i;
        }
    }
    if(x>1)
        factor[x]++;
}
int n;
int primes[N], cnt;
bool st[N * 10];
void find_primes(int x)
{
    for (int i = 2; i <= x; i++)
    {
        if(!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= x / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main()
{
    find_primes(1e6);
    int t;
    scanf("%d", &t);
    while (t--)
    {
        factor.clear();
        for (auto prime:primes)
            factor[prime] = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            ll a;
            scanf("%lld", &a);
            find_factor(a);
        }
        ll res = -1;
        for(auto prime : primes)
        {
            if(!factor[prime])
            {
                res = prime;
                break;
            }
        }
        printf("%lld\n", res);
    }

    return 0;
}