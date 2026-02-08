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
    PII res = {-1, 0};
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int num;
        cin >> num;
        if (res.first == -1 || num >= res.second)
            res = {i, num};
    }

    cout << res.first << '\n';
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