#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int gcd(int x, int y)
{
    return !y ? x : gcd(y, x % y);
}

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];

    // precompute valid subsets (cliques)
    vector<bool> valid(1 << n, true);
    for (int mask = 1; mask < (1 << n); mask++)
    {
        vector<int> indices;
        for (int i = 0; i < n; i++)
        {
            if (mask >> i & 1)
                indices.push_back(i);
        }
        for (int i = 0; i < indices.size(); i++)
        {
            for (int j = i + 1; j < indices.size(); j++)
            {
                if (gcd(a[indices[i]], a[indices[j]]) != 1)
                {
                    valid[mask] = false;
                    break;
                }
            }
            if (!valid[mask])
                break;
        }
    }

    // DP: f[mask] = 覆盖mask状态所需的最少组数
    vector<int> f(1 << n, n);
    f[0] = 0;
    for (int mask = 1; mask < (1 << n); mask++)
    {
        // 枚举最后一个组（必须是valid的subset）
        for (int submask = mask; submask; submask = (submask - 1) & mask)
        {
            if (valid[submask])
            {
                f[mask] = min(f[mask], f[mask ^ submask] + 1);
            }
        }
    }

    cout << f[(1 << n) - 1];
    return 0;
}