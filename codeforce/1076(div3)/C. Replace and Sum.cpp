#include <iostream>

using namespace std;

const int N = 2e5 + 10;

long long a[N], b[N];
int n, q, l, r;

void solve()
{
    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> a[i];
    for (int i = 1; i <= n; i++)
        cin >> b[i];

    for (int i = 1; i <= n; i++)
        a[i] = max(a[i], b[i]);
    for (int i = n - 1; i >= 1; i--)
        a[i] = max(a[i], a[i + 1]);
    for (int i = 1; i <= n; i++)
        a[i] += a[i - 1];
    while (q--)
    {
        cin >> l >> r;
        cout << a[r] - a[l - 1]  << " ";
    }
    cout << "\n";
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