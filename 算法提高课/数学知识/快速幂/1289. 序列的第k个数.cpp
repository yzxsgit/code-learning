#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int p = 200907;

int qmi(int a, int k)
{
    int res = 1;
    while (k)
    {
        if (k & 1)
            res = (i64)res * a % p;
        a = (i64)a * a % p;
        k >>= 1;
    }
    return res;
}

void solve()
{
    int a, b, c, k;
    cin >> a >> b >> c >> k;

    if ((i64)a + c == (i64)2 * b)
    {
        cout << (a + (b - a) * (i64)(k - 1)) % p << '\n';
    }
    else 
    {
        cout << (i64)a * qmi(b / a, k - 1) % p << '\n';
    }
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