#include <iostream>
#include <vector>

using std::abs;
using std::cin;
using std::cout;
typedef long long ll;
    
ll x, y;
ll ansp, ansq;
void check(ll &min, ll p, ll q)
{
    if (p & q)
        return;
    else if (abs(x - p) + abs(y - q) < min)
    {
        min = abs(x - p) + abs(y - q);
        ansp = p;
        ansq = q;
    }
}

void solve()
{
    ll min = 1e18;
    cin >> x >> y;
    check(min, x, y);
    if (min == 0)
    {
        return;
    }

    for (int i = 29; i >= 0; i--)
    {
        if ((x & y) >> i & 1)
        {
            check(min, (x >> i << i) + (1LL << i), y);
            check(min, x, (y >> i << i) + (1LL << i));
            check(min, x >> i << i, (y >> i << i) - 1);
            check(min, (x >> i << i) - 1, y >> i << i);
        }
    }
}

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        solve();
        cout << ansp << " " << ansq << '\n';
    }

    return 0;
}