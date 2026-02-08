#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 2010;

int f[N][N];
int n;
string s;

int dp(int l, int r)
{
    if (l > r) return 0;

    if(f[l][r] != -2)
        return f[l][r];

    int tmp_l;
    {
        int sub_l = dp(l + 2, r);
        if (sub_l == 0)
        {
            if(s[l] < s[l + 1])
                sub_l = 1;
            else if (s[l] > s[l + 1])
                sub_l = -1;
        }
        int sub_r = dp(l + 1, r - 1);
        if (sub_r == 0)
        {
            if (s[l] < s[r])
                sub_r = 1;
            else if (s[l] > s[r])
                sub_r = -1;
        }
        tmp_l = min(sub_l, sub_r);
    }

    int tmp_r;
    {
        int sub_l = dp(l + 1, r - 1);
        if (sub_l == 0)
        {
            if (s[r] < s[l])
                sub_l = 1;
            else if (s[r] > s[l])
                sub_l = -1;
        }
        int sub_r = dp(l, r - 2);
        if (sub_r == 0)
        {
            if (s[r] < s[r - 1])
                sub_r = 1;
            else if (s[r] > s[r - 1])
                sub_r = -1;
        }
        tmp_r = min(sub_r, sub_l);
    }
    f[l][r] = max(tmp_l, tmp_r);
    return f[l][r];
}

void solve()
{
    cin >> s;
    n = s.size();
    for (int i = 0; i <= n; i++)
        for (int j = 0; j <= n; j++)
            f[i][j] = -2;

    int res = dp(0, n - 1);
    if (res == 1)
        cout << "Alice\n";
    else if (res == 0)
        cout << "Draw\n";
    else
        cout << "Bob\n";
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