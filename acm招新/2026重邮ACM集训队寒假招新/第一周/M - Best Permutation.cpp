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
    if(n % 2)
    {
        cout << 1 << ' ';
        for (int i = n - 2; i >= 2; i--)
        cout << i << ' ';
    }
    else
    {
        for (int i = n - 2; i; i--)
            cout << i << ' ';
    }
    cout << n - 1 << ' ' << n << '\n';
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