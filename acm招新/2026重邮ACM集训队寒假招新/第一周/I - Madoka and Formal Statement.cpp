#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 2e5 + 10;

int a[N], b[N];
int n;

void solve()
{
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    a[n] = a[0], b[n] = b[0];

    bool flag = true;
    for (int i = n - 1; i >= 0; i--)
    {
        int tmp = max(a[i + 1], b[i + 1]);
        if (a[i] > b[i] || a[i] < b[i] && b[i] - 1 > tmp)
        {
            flag = false;
            break;
        }
    }

    cout << (flag ? "YES\n" : "NO\n");
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