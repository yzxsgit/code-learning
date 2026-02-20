#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e7 + 10;

int cnt;
int phi[N], primes[N];
bool st[N];

void init(int n)
{
    phi[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            int p = primes[j];
            st[p * i] = true;
            if (i % p == 0)
            {
                phi[p * i] = phi[i] * p;
                break;
            }
            phi[p * i] = phi[i] * (p - 1);
        }
    }

}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    vector<i64> s(n + 1);
    init(n);

    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + phi[i];

    i64 res = 0;
    for (int i = 0; i < cnt; i++)
    {
        int p = primes[i];
        res += s[n / p] * 2 + 1;
    }

    cout << res << '\n';

    return 0;
}