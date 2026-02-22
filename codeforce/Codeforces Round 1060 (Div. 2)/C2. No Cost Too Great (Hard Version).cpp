#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

void solve()
{
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    // 计算前缀和
    vector<ll> prefix(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        prefix[i + 1] = prefix[i] + a[i];
    }

    ll ans = prefix[n]; // 初始总和

    // 考虑所有可能的奇数x
    for (int x = 1; x <= n; x += 2)
    {
        // 最大中位数对应的索引
        int idx = n - (x - 1) / 2 - 1;
        ll M = a[idx];

        // 计算最多能获得多少个M
        // 第一次操作：获得x个M
        // 后续每次操作：可以获得(x+1)/2个新的M
        ll total_M = 0;
        if (k > 0)
        {
            total_M = x;
            int remaining = n - x;
            int ops_left = k - 1;

            // 后续操作
            while (ops_left > 0 && remaining > 0)
            {
                total_M += (x + 1) / 2;
                remaining -= (x + 1) / 2;
                ops_left--;
            }

            total_M = min(total_M, (ll)n);

            // 新总和 = 用M替换最小的total_M个数
            ll new_sum = prefix[n] - prefix[total_M] + total_M * M;
            ans = max(ans, new_sum);
        }
    }

    cout << ans << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
    return 0;
}