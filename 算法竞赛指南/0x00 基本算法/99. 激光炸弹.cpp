#include <bits/stdc++.h>

using namespace std;

const int N = 5009;

int w[N][N]; // 二位前缀和数组
int n, r, ans = 0;

int main()
{
    cin >> n >> r;

    r = min(r, 5001);

    for (int i = 1, x, y, k; i <= n; ++i)
    {
        cin >> x >> y >> k;
        w[x + 1][y + 1] += k;
    }
    for (int i = 1; i <= 5001; ++i)    
        for (int j = 1; j <= 5001; ++j)
            w[i][j] = w[i - 1][j] + w[i][j - 1] - w[i - 1][j - 1] + w[i][j];

    for (int i = r; i <= 5001; ++i)
        for (int j = r; j <= 5001; ++j)
            ans = max(ans, w[i][j] - w[i - r][j] - w[i][j - r] + w[i - r][j - r]);

    cout << ans << endl;
    return 0;
}
