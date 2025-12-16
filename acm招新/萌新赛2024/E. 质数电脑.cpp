#include <iostream>

using namespace std;
bool st[10010];
int primes[10010], cnt;
void find_primes(int x)
{
    for (int i = 2; i <= x; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= x / i; j++)
        {
            st[primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main()
{
    find_primes(10000);

    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n;
        scanf("%d", &n);
        int a = 0, b = 0;
        while (n--)
        {
            long long x;
            scanf("%lld", &x);
            if (x > 10000)
                a++;
            else if (!st[x])
                b++;
            else
                a++;
        }
        cout << (a > b ? "Yes" : "No") << "\n";
    }

    return 0;
}