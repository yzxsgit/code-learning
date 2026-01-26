#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

typedef long long LL;
const int N = 2e5 + 10, mod = 1e9 + 7;

struct DOTS {
    int x, y;
} g[N];

struct Column {
    int x, minY, maxY;
};

void solve() {
    int n;
    LL Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;

    for (int i = 1; i <= n; i++) cin >> g[i].x;
    for (int i = 1; i <= n; i++) cin >> g[i].y;

    // 1. 排序并合并相同 x 的点
    sort(g + 1, g + n + 1, [](DOTS a, DOTS b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
    });

    vector<Column> cols;
    // 起点作为一个特殊的列
    cols.push_back({(int)Ax, (int)Ay, (int)Ay});

    for (int i = 1; i <= n; i++) {
        if (!cols.empty() && g[i].x == cols.back().x) {
            cols.back().minY = min(cols.back().minY, g[i].y);
            cols.back().maxY = max(cols.back().maxY, g[i].y);
        } else {
            cols.push_back({g[i].x, g[i].y, g[i].y});
        }
    }
    // 终点作为一个特殊的列
    if (cols.back().x == Bx) {
        cols.back().minY = min(cols.back().minY, (int)By);
        cols.back().maxY = max(cols.back().maxY, (int)By);
    } else {
        cols.push_back({(int)Bx, (int)By, (int)By});
    }

    int m = cols.size();
    // dp[i][0] 表示停在第 i 列的 minY，dp[i][1] 表示停在 maxY
    vector<vector<LL>> dp(m, vector<LL>(2, 0));

    // 初始状态（起点 Ax, Ay 已经在 cols[0]）
    dp[0][0] = dp[0][1] = 0; 

    for (int i = 1; i < m; i++) {
        LL L = cols[i].minY, R = cols[i].maxY;
        LL pL = cols[i-1].minY, pR = cols[i-1].maxY;

        // 转移到当前的 L (必须经过 R 再回到 L)
        // 1. 从 pL -> R -> L
        // 2. 从 pR -> R -> L
        dp[i][0] = min(dp[i-1][0] + abs(pL - R) + (R - L),
                       dp[i-1][1] + abs(pR - R) + (R - L));

        // 转移到当前的 R (必须经过 L 再回到 R)
        // 1. 从 pL -> L -> R
        // 2. 从 pR -> L -> R
        dp[i][1] = min(dp[i-1][0] + abs(pL - L) + (R - L),
                       dp[i-1][1] + abs(pR - L) + (R - L));
    }

    // 最终垂直位移：从最后一列（包含 By）的两个端点走到 By
    LL final_v = min(dp[m-1][0] + abs(cols[m-1].minY - By), 
                    dp[m-1][1] + abs(cols[m-1].maxY - By));
    
    LL horizontal_dist = Bx - Ax;
    
    // 注意：题目要求对 10^9+7 取模
    cout << (final_v + horizontal_dist) % mod << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;
    while (T--) solve();
    return 0;
}