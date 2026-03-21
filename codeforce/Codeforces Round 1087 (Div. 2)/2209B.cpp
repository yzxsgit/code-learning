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

vector<int> a;

void solve()
{
    int n;
    cin >> n;

    a.resize(n);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        int l = 0, r = 0;
        for (int j = i + 1; j < n; j++)
            if (a[i] > a[j])
                l++;
            else if (a[i] < a[j])
                r++;
        cout << max(l, r) << ' ';
    }
    cout << '\n';
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