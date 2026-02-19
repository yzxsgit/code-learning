#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int p = 100003;

int qmi(int a, i64 k)
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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    i64 n, m;
    cin >> m >> n;

    int res = qmi(m, n) - (i64)m * qmi(m - 1, n - 1) % p;
    res = (res % p + p) % p;
    cout << res << '\n';

    return 0;
}