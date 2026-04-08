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

    vector<int> a(n), b(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    vector<bool> A(n + 1, false), B(n + 1, false);

    for (int i = 0; i < n; i++)
    {
        if (i < n - k || i >= k)
        {
            if (b[i] != -1 && b[i] != a[i])
            {
                cout << "NO\n";
                return;
            }
        }
        else
        {
            A[a[i]] = true;
        }
    }

    for (int i = n - k; i < k; i++)
    {
        if (b[i] != -1)
        {
            if (!A[b[i]] || B[b[i]])
            {
                cout << "NO\n";
                return;
            }
            B[b[i]] = true;
        }
    }

    cout << "YES\n";
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