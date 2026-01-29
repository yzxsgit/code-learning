#include <iostream>

using namespace std;

long long p, q;
void solve()
{
    long long a, b;
    cin >> a >> b;
    int n = 1e6;
    if (!a && !b)
    {
        p = q = 0;
        return;
    }
    for (int i = 1; i <= n; i++)
    {
        p = a, q = abs(b - i);
        if (!(p & q))
            return;
        p = a, q = b + i;
        if (!(p & q))
            return;
        p = abs(a - i), q = b;
        if (!(p & q))
            return;
        p = a + i, q = b;
        if (!(p & q))
            return;
    }
}

int main()
{
    int T;
    cin >> T;
    while (T--)
    {
        solve();
        cout << p << " " << q << "\n";
    }
}