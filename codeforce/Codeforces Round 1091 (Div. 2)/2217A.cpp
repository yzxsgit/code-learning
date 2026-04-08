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

    int x = 0;
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        x += a;
    }

    cout << (n * k % 2 == 0 || x % 2 == 1 ? "YES\n" : "NO\n");
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