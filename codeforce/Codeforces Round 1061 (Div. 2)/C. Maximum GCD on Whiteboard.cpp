#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;

        vector<int> a(n);
        vector<int> freq(n + 1, 0);

        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (a[i] <= n)
            {
                freq[a[i]]++;
            }
        }

        // 计算前缀和 p[v] = sum_{u=1 to v} freq[u]
        vector<int> p(n + 1, 0);
        for (int i = 1; i <= n; i++)
        {
            p[i] = p[i - 1] + freq[i];
        }

        int ans = 1;
        // 从大到小遍历 g
        for (int g = n; g >= 1; g--)
        {
            // 计算 good(g)
            int count = 0;

            // 加上 x = g, x = 2g, x = 3g 的个数
            if (g <= n)
                count += freq[g];
            if (2 * g <= n)
                count += freq[2 * g];
            if (3 * g <= n)
                count += freq[3 * g];

            // 加上 x >= 4g 的个数
            int threshold = min(n, 4 * g - 1);
            count += n - p[threshold];

            if (count >= n - k)
            {
                ans = g;
                break;
            }
        }

        cout << ans << '\n';
    }

    return 0;
}