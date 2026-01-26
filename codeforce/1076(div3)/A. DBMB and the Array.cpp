#include <iostream>

using namespace std;

void solve()
{
    int n, s, x, now = 0;

    cin >> n >> s >> x;

    while (n--)
    {
        int a;
        cin >> a;
        now += a;
    }

    cout << (((s - now) % x || s < now) ? "NO\n" : "YES\n");
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}