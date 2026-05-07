#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <functional>
#include <array>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    cout << ((n - 1) % __gcd(n, a) == 0 && (m - 1) % __gcd(m, b) == 0 && __gcd(n, m) <= 2 ? "YES\n" : "NO\n");
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}