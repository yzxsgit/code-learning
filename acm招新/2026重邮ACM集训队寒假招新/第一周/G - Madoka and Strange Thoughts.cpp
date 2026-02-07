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
    cout << n + 2 * (n / 2 + n / 3) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int T;
    cin>>T;
    while (T--)
    {
        solve();
    }
    return 0;
}