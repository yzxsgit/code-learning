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

bool st[N];
vector<int> primes;

void get_primes(int n)
{
    for (int i = 2; i <= n; i++)
    {
        if (!st[i])
            primes.push_back(i);
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

    get_primes(1e6);

    st[1] = true;
    int n;
    while (cin >> n && n)
    {
        auto i = lower_bound(primes.begin(), primes.end(), n) - 1;
        while (i > primes.begin())
        {
            if (!st[n - *i])
            {
                cout << n << " = " << n - *i << " + " << *i << '\n';
                break;
            }
            i--;
        }
        if (i == primes.begin())
            cout << "Goldbach's conjecture is wrong.\n";
    }   

    return 0;
}