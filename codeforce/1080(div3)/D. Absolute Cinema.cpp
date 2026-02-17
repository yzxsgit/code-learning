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
    vector<i64> f(n + 1), s(n + 1);

    for (int i = 1; i <= n; i++)
    {
        cin >> f[i];
    }

    s[n] = f[1] + f[n];
    s[n] /= n - 1;

    for (int i = 2; i <= n; i++)
    {
        s[i - 1] = (f[i] - f[i - 1] + s[n]) / 2;
    }


    for (int i = 1; i <= n; i++)
        cout << s[i] - s[i - 1] << ' ';
    cout << '\n';
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