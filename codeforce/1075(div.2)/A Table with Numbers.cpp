#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

void solve()
{
    int n, h, l;
    cin >> n >> h >> l;

    int count_h = 0;
    int count_l = 0;
    int total = 0; 
    for (int i = 0; i < n; i++)
    {
        int a;
        cin >> a;
        bool useful = false;
        if (a <= h)
        {
            count_h++;
            useful = true;
        }
        if (a <= l)
        {
            count_l++;
            useful = true;
        }
        if (useful)
            total++;
    }

    int res = min({count_h, count_l, total / 2});

    cout << res << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}