#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 5e4 + 10;

vector<bool> st(N);
vector<int> primes;

void init(int n)
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

void solve(int l, int r)
{
    vector<int> range_primes;
    vector<bool> range_st(1e6 + 10, 0);

    for (i64 p : primes)
    {
        for (i64 j = max(p * 2, (i64)(l + p - 1) / p * p); j <= r; j += p)
            range_st[j - l] = true;
    }

    for (int i = 0; i <= r - l; i++)
        if (!range_st[i] && (i64) l + i >= 2)
            range_primes.push_back(i + l);
    
    int m = range_primes.size();
    if (m < 2)
    {
        cout << "There are no adjacent primes.\n";
        return;
    }
    
    int min_idx = 0, max_idx = 0;  
    
    for (int i = 0; i + 1 < m; i++)
    {
        int d = range_primes[i + 1] - range_primes[i];
        
        if (d < range_primes[min_idx + 1] - range_primes[min_idx])
            min_idx = i;
            
        if (d > range_primes[max_idx + 1] - range_primes[max_idx])
            max_idx = i;
    }
    
    cout << range_primes[min_idx] << ',' << range_primes[min_idx + 1] 
         << " are closest, ";
    cout << range_primes[max_idx] << ',' << range_primes[max_idx + 1] 
         << " are most distant.\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    init(N - 1);

    int l, r;
    while (cin >> l >> r)
    {
        solve(l, r);
    }
    
    return 0;
}