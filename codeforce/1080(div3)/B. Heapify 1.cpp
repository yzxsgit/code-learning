#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

bool check(int x, int y)
{
    while (x % 2 == 0 && x)
        x /= 2;
    
    while (y % 2 == 0 && y)
        y /= 2;
    return x != y;
}

void solve()
{
    int n;
    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin>> a[i];
    bool ans = true;
    for (int i = 1; i <= n; i++)
    {
        if (check(i, a[i]))
        {
            ans = false;
            break;
        }
    }
    cout << (ans ? "YES\n" : "NO\n");

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