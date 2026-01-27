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
bool cmp(DOTS a, DOTS b) {
        if (a.x != b.x) return a.x < b.x;
        return a.y < b.y;
}
struct Column {
    int x, minY, maxY;
};

void solve() {
    int n;
    LL Ax, Ay, Bx, By;
    cin >> n >> Ax >> Ay >> Bx >> By;

    for (int i = 1; i <= n; i++) 
        cin >> g[i].x;
    for (int i = 1; i <= n; i++) 
        cin >> g[i].y;

    sort(g + 1, g + n + 1, cmp);

    vector<Column> cols;
    cols.push_back({(int)Ax, (int)Ay, (int)Ay});

    for (int i = 1; i <= n; i++) {
        if (!cols.empty() && g[i].x == cols.back().x) {
            cols.back().minY = min(cols.back().minY, g[i].y);
            cols.back().maxY = max(cols.back().maxY, g[i].y);
        } else {
            cols.push_back({g[i].x, g[i].y, g[i].y});
        }
    }
    if (cols.back().x == Bx) {
        cols.back().minY = min(cols.back().minY, (int)By);
        cols.back().maxY = max(cols.back().maxY, (int)By);
    } else {
        cols.push_back({(int)Bx, (int)By, (int)By});
    }

    int m = cols.size();
    vector<vector<LL>> dp(m, vector<LL>(2, 0));

    dp[0][0] = dp[0][1] = 0; 

    for (int i = 1; i < m; i++) {
        LL L = cols[i].minY, R = cols[i].maxY;
        LL pL = cols[i-1].minY, pR = cols[i-1].maxY;

        dp[i][0] = min(dp[i-1][0] + abs(pL - R) + (R - L),
                       dp[i-1][1] + abs(pR - R) + (R - L));

        dp[i][1] = min(dp[i-1][0] + abs(pL - L) + (R - L),
                       dp[i-1][1] + abs(pR - L) + (R - L));
    }

    LL final_v = min(dp[m-1][0] + abs(cols[m-1].minY - By), 
                    dp[m-1][1] + abs(cols[m-1].maxY - By));
    
    LL horizontal_dist = Bx - Ax;
    
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