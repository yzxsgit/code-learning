#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int INF = 1e9;

void solve() 
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; ++i) 
    {
        cin >> a[i];
    }

    vector<int> dp(7, 0);

    for (int j = 1; j <= 6; ++j) 
    {
        dp[j] = (a[0] == j ? 0 : 1);
    }

    for (int i = 1; i < n; ++i) 
    {
        vector<int> next_dp(7, INF);
        for (int j = 1; j <= 6; ++j) 
        {
            int cost = (a[i] == j ? 0 : 1);
            
            for (int k = 1; k <= 6; ++k) 
            {
                if (k != j && k + j != 7) 
                {
                    next_dp[j] = min(next_dp[j], dp[k] + cost);
                }
            }
        }
        dp = next_dp;
    }

    int ans = INF;
    for (int j = 1; j <= 6; ++j) 
    {
        ans = min(ans, dp[j]);
    }
    cout << ans << "\n";
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