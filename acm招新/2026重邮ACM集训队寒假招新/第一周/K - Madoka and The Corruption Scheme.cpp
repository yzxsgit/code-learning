#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n, k;
    cin >> n >> k;

    i64 mod = 1e9 + 7;

    i64 res = 0;

    if (k < n)
    {
        while (n)
        {
            if (k >= n)
            {
                res = ((res << 1) + 1) % mod;
                k--;
                n--;
            }
            else
            {
                res = (res << 1) % mod;
                n--;
            }
        }

        res = ((res << 1) + 1) % mod;
    }
    else 
    {
        res = 1;
        while (n)
        {
            res = (res << 1) % mod;
                n--;
        }
    }
    cout << res << '\n';

    return 0;
}