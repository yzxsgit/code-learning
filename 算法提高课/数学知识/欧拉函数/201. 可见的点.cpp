#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e4 + 10;

int cnt;
int phi[N], primes[N];
bool st[N];

void init(int n)
{
    phi[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
        {
            primes[cnt++] = i;
            phi[i] = i - 1;
        }
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
            {
                phi[i * primes[j]] = phi[i] * primes[j];
                break;
            }
            phi[i * primes[j]] = phi[i] * (primes[j] - 1);
        }
    }
}

void solve(int t)
{
    int n;
    cin >> n;

    i64 res = 0;

    vector<int> s(n + 1);

    for (int i = 1; i <= n; i++)
        s[i] = s[i - 1] + phi[i];
    res = s[n] * 2 + 1;

    cout << t << ' ' << n << ' ' << res << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    init(N - 1);

    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
    {
        solve(i);
    }
    return 0;
}