#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 45000, M = 50;

int primes[N], cnt;
bool st[N];
vector<PII> factors;
vector<int> divider;

void init(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[i * primes[j]] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void dfs(int u, int p)
{
    if (u >= factors.size())
    {
        divider.push_back(p);
        return;
    }

    for (int i = 0; i <= factors[u].second; i++)
    {
        dfs(u + 1, p);
        p *= factors[u].first;
    }
}

void solve()
{
    int a0, a1, b0, b1;
    cin >> a0 >> a1 >> b0 >> b1;

    int d = b1;
    factors.clear();
    for (int i = 0; primes[i] <= d / primes[i]; i++)
    {
        int p = primes[i];
        if (d % p == 0)
        {
            int s = 0;
            while (d % p == 0)
            {
                d /= p;
                s++;
            }
            factors.push_back({p, s});
        }
    }
    if (d > 1)
        factors.push_back({d, 1});
    
    divider.clear();
    dfs(0, 1);

    int res = 0;
    for (int x : divider)
        if (gcd(x, a0) == a1 && (i64)x * b0 / gcd(x, b0) == b1)
            res++;

    cout << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    init(N - 1);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}