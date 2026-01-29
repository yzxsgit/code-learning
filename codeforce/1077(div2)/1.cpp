#include <iostream>
#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> ones;
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') ones.push_back(i);
    }

    if (ones.empty()) {
        // 全是0的情况：每3个位子放一个，如 00100
        return (n + 2) / 3;
    }

    long long total = ones.size();

    // 1. 处理左边界 (第一个 1 之前的 0)001
    int left_zeros = ones[0];
    total += left_zeros / 3;

    // 2. 处理两个 1 之间的 0 100000001
    for (size_t i = 0; i < ones.size() - 1; i++) {
        int gap = ones[i+1] - ones[i] - 1;
        if (gap >= 3) {
            // 中间段公式: (gap - 1) / 3
            total += gap/3;
        }
    }

    // 3. 处理右边界 (最后一个 1 之后的 0)
    int right_zeros = n - 1 - ones.back();
    total += right_zeros / 3;

    return total;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
    while (t--) {
        cout << solve() << "\n";
    }
    return 0;
}