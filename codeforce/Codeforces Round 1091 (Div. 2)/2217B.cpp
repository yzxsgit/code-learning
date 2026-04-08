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

void solve()
{
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    int g;
    cin >> g;
    g--;
    int l = 0, r = 0;
    for (int i = 0; i < g; i++)
        if (a[i] != a[i + 1] && a[i] != a[g])
            l++;
    for (int i = g + 1; i < n; i++)
        if (a[i - 1] != a[i] && a[i] != a[g])
            r++;

    cout << max(r, l) * 2 << '\n';
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