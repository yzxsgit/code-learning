#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

void solve()
{
    int n;
    cin >> n;
    int k = 1;
    for (int i = 2; i <= n / i; i++)
    {
        if (n % i == 0)
        {
            while (n % i == 0)
                n /= i;
            k *= i;
        }
    }
    if (n > 1)
    {
        k *= n;
    }

    cout << k << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}