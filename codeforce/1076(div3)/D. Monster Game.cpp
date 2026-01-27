#include <iostream>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

long long a[N], b[N];
int n;

void solve()
{
    cin >> n;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    sort(a + 1, a + n + 1);
    for (int i = 1; i <= n; i++)
        b[i] += b[i - 1];

    long long res = 0;
    for (int i = n; i > 0; i--)
    {
        if (b[i] > n)
            continue;
        int x = a[n - b[i] + 1];

        res = max(res, (long long)x * i);
    }

    cout << res << "\n";
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