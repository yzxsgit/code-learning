#include <bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
int n;
int prime[N];
bool st[N];
int primes(int x)
{
    int cnt = 0;
    for (int i = 2; i <= x; i++)
    {
        if (!st[i])
            prime[cnt++] = i;
        for (int j = 0; prime[j] <= x / i; j++)
        {
            st[prime[j] * i] = true;
            if (i % prime[j] == 0)
                break;
        }
    }
    return cnt;
}
int main()
{
    scanf("%d", &n);
    printf("%d", primes(n));
    return 0;
}