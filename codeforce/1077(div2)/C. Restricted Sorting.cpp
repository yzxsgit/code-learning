#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int solve()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    auto b = a;
    sort(b.begin(), b.end());
    int minn = b[0], maxx = b[n - 1];

    int k = 0x3f3f3f3f;
    for (int i = 0; i < n; i++)
        if (a[i] != b[i])
        {
            k = min(k, max(maxx - a[i], a[i] - minn));
        }

    return k == 0x3f3f3f3f ? -1 : k;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int T;
    cin>>T;

    while (T--)
    {
        cout << solve() << "\n";
    }

    return 0;
}