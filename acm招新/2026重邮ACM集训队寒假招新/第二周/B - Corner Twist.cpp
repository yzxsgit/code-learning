#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

void solve()
{
    int n, m;
    cin >> n >> m;

    vector<string> a(n), b(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];

    bool res = true;
    int A, B;
    for (int i = 0; i < n; i++)
    {
        A = 0, B = 0;
        for (int j = 0; j < m; j++)
        {
            A += a[i][j] - '0';
            B += b[i][j] - '0';
        }
        if (A % 3 != B % 3)
        {
            res = false;
            break;
        }
    }

    for (int j = 0; j < m; j++)
    {
        A = 0, B = 0;
        for (int i = 0; i < n; i++)
        {
            A += a[i][j] - '0';
            B += b[i][j] - '0';
        }
        if (A % 3 != B % 3)
        {
            res = false;
            break;
        }
    }

    cout << (res ? "YES\n" : "NO\n");
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