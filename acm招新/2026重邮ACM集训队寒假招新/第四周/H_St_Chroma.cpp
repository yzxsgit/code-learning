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
    int n, x;
    cin >> n >> x;
    for (int i = 0; i < x; i++)
        cout << i << ' ';
    for (int i = x + 1; i < n; i++)
        cout << i << ' ';

    if (x < n)
    {
        cout << x;
    }

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