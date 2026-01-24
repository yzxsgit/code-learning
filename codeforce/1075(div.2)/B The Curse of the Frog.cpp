#include <iostream>
#include <cstring>

using namespace std;

void solve()
{
    int n;
    long long target;
    cin >> n >> target;

    long long free = 0, max_roll = -1e18;

    for (int i = 0; i < n; i++)
    {
        long long a, b, c;
        cin >> a >> b >> c;

        free += a * (b - 1);
        long long gain = b * a - c;
        if(gain > max_roll)
            max_roll = gain;
    }

    if(free >= target)
    {
        cout << 0 << "\n";
        return;
    }
    if(max_roll <= 0)
    {
        cout << -1 << "\n";
        return;
    }

    long long need = target - free;
    long long ans = (need + max_roll - 1) / max_roll;

    cout << ans << "\n";
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