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
using PII = pair<int, int>;

int gcd(int a, int b)
{
    return b ? gcd(b, a % b) : a;
}

void solve()
{
    int n, m, a, b;
    cin >> n >> m >> a >> b;

    bool flag1 = (n - 1) % gcd(n, a) == 0;
    bool flag2 = (m - 1) % gcd(m, b) == 0;
    bool flag3 = (gcd(n, m) <= 2);
    cout << (flag1 && flag2 && flag3 ? "YES\n" : "NO\n");
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