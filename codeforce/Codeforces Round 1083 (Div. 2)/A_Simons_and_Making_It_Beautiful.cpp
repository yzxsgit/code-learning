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
    vector<int> q(n);

    int maxx = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> q[i];
        if (q[i] == n)
            maxx = i;
    }

    swap(q[0], q[maxx]);

    for (int res : q)
        cout << res << ' ';
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