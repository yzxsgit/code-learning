#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int primes[N], idx;
bool st[N];
int euler[N];
void get_euler(int x)
{
    euler[1] = 1;
    for (int i = 2; i <= x; i++)
    {
        if (!st[i])
        {
            primes[idx++] = i;
            euler[i] = i - 1;
        }
        for (int j = 0; primes[j] <= x / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                euler[primes[j] * i] = primes[j] * euler[i];
                break;
            }
            euler[primes[j] * i] = euler[i] * (primes[j] - 1);
        }
    }
}
int main()
{
    int n;
    scanf("%d", &n);

    get_euler(n);

    long long ans = 0;

    for (int i = 1; i <= n; i++)
        ans += euler[i];

    printf("%lld\n", ans);

    return 0;
}
