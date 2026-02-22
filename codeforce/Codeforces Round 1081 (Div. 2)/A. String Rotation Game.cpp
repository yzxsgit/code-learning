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
    int n;
    string str;
    cin >> n;
    cin >> str;

    int res = 1;
    bool flag = false;
    for (int i = 1; i < n; i++)
        if (str[i] != str[i - 1])
            res++;
        else
            flag = true;
    res += (str[0] != str[n - 1] && flag);

    cout << res << '\n';
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