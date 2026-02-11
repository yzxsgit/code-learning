#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1), p(n + 1), f(n + 1), b(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        f[a[i]] = i;
    }
    for (int i = 1; i <= n; i++)
        cin >> p[i];
    for (int i = 1; i <= n; i++)
    {
        b[i] = f[p[i]];
    }

    bool res = true;
    for (int i = 2; i <= n; i++)
        if (b[i] < b[i - 1])
        {
            res = false;
        }

    cout << (res ? "YES" : "NO") << '\n';
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