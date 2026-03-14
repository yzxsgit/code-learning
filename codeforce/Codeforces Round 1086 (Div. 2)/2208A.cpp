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
    vector<int> num(n * n + 1, 0);

    for (int i = 0; i < n * n; i++)
    {
        int a;
        cin >> a;
        num[a]++;
    }

    for (int i = 1; i <= n * n; i++)
    {
        if (num[i] > n *(n - 1))
        {
            cout << "NO\n";
            return;
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