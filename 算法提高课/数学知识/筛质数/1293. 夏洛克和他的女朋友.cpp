#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e5 + 10;

vector<bool> st(N, 0);
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

    get_primes(1e5 + 1);

    int n;
    cin >> n;
    if (n >= 3)
        cout << 2 << '\n';
    else
        cout << 1 << '\n';
    for (int j = 2, k = 1; j <= n + 1; j++)
    {
        if (st[j])
        {
            cout << 2 << ' ';
        }
        else 
        {
            cout << 1 << ' ';
        }
    }

    return 0;
}