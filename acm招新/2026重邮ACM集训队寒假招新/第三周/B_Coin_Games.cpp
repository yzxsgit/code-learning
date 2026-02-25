#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

void solve()
{
    int n;
    cin >> n;
    string x;
    cin >> x;

    int cnt = 0;
    for (int i = 0; i < x.size(); i++)
    {
        if (x[i] == 'U')
            cnt++;
    }

    cout << (cnt % 2 ? "YES\n" : "NO\n");
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