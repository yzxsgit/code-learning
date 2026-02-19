#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e6 + 10;

int cnt;
int primes[N];
bool st[N];

void init(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes[cnt++] = i;
        for (int j = 0; primes[j] <= n / i; j++)
        {
            st[primes[j] * i] = true;
            if (i % primes[j] == 0)
                break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;
    cin >> n;
    init(n);

    for (int i = 0; i < cnt; i++)
    {
        int p = primes[i];
        int s = 0;

        for (int j = n; j; j /= p)
        {
            s += j / p;
        }
        cout << p << ' ' << s << '\n';
    }

    return 0;
}