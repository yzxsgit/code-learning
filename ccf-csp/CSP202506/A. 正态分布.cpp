#include <iostream>
#include <cmath>
using namespace std;

void solve()
{
    double a, b, n;
    cin >> a >> b >> n;
    double z = (n - a) / b;
    int ans = round(z * 100);
    cout << ans / 10 + 1 << " " << ans % 10 + 1 << endl;
}

int main()
{
    int k;
    cin >> k;
    while (k--)
    {
        solve();
    }
    return 0;
}