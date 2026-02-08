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
    int n, k, r, c;
    cin >> n >> k >> r >> c;

    int flag = (r + c) % k;

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
            if ((i + j) % k == flag)
                cout << 'X';
            else
                cout << '.';
        cout << '\n';
    }
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