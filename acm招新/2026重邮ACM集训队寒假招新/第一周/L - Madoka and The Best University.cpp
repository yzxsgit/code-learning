#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    cin >> n;
    
    // 预处理欧拉函数
    vector<int> phi(n + 1);
    for (int i = 0; i <= n; i++) phi[i] = i;
    for (int i = 2; i <= n; i++) {
        if (phi[i] == i) {  // i是质数
            for (int j = i; j <= n; j += i) {
                phi[j] -= phi[j] / i;
            }
        }
    }
    
    ll ans = 0;
    for (int d = 1; d <= n - 2; d++) {
        int max_s = (n - 1) / d;  // 最大的s使得 d*s < n，即 c = n - d*s > 0
        if (max_s < 2) continue;
        
        for (int s = 2; s <= max_s; s++) {
            int c = n - d * s;
            // lcm(c, d) = c / gcd(c, d) * d
            int g = gcd(c, d);
            ll l = (ll)c / g * d;
            ans = (ans + (ll)phi[s] * l) % MOD;
        }
    }
    
    cout << ans << endl;
    return 0;
}