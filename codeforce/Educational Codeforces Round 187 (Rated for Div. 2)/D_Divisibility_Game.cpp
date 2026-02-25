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
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < m; i++)
        cin >> b[i];

    sort(a.begin(), a.end());
    a.erase(unique(a.begin(), a.end()), a.end());

    int N = n + m;
    vector<int> cnt(N + 1, 0);

    n = a.size();
    for (int x : a)
        for (int mul = x; mul <= N; mul += x)
        {
            cnt[mul]++;
        }

    int c1 = 0, c2 = 0, c3 = 0;

    for (int i : b)
    {
        int d = cnt[i];
        if (d == n)
        {
            c1++;
        }
        else if (d ==0)
        {
            c3++;
        }
        else
        {
            c2++;
        }
    }

    cout << (2 * c1 + (c2 & 1) > 2 * c3 ? "Alice\n" : "Bob\n");
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