#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

void solve() {
    int n, m;
    if (!(cin >> n >> m)) return;

    // 邻接表，存图。注意题目是 1-based。
    // 为了方便匹配，我们不仅需要存边，还需要知道每个点能跳到的最远点 P[u]。
    vector<vector<int>> adj(n + 1);
    
    // 基础边 u -> u+1
    for (int i = 1; i < n; ++i) {
        adj[i].push_back(i + 1);
    }
    
    // 额外边
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
    }

    // 计算 P[u] 并对 adj 进行排序以备后续二分或线性扫描
    vector<int> P(n + 1);
    for (int i = 1; i < n; ++i) {
        sort(adj[i].begin(), adj[i].end());
        P[i] = adj[i].back();
    }

    // cnt[v] 记录有多少个 active 的 x 满足 P[x] == v
    vector<int> cnt(n + 1, 0);
    // 维护当前所有 P[x] > y 的目标集合。利用 set 自动排序。
    set<int> active_targets;
    
    long long total_ans = 0;

    // 枚举 Tom 的位置 y，从 2 到 n
    for (int y = 2; y <= n; ++y) {
        // 新加入的 x 是 y-1
        int prev_x = y - 1;
        int target = P[prev_x];
        
        // 将 P[y-1] 加入活跃集合
        // 注意：只有当 P[y-1] > y 时它才构成威胁。
        // 但我们稍后会统一清理 <= y 的值，所以先加入无妨。
        cnt[target]++;
        active_targets.insert(target);
        
        // 移除不再构成威胁的目标（即 target <= y 的部分）
        // 因为 y 是递增的，所以每次只需检查 set 开头
        while (!active_targets.empty() && *active_targets.begin() <= y) {
            int to_remove = *active_targets.begin();
            active_targets.erase(active_targets.begin());
            // 清理计数（虽然逻辑上不清理也不影响后续正确性，因为该值已从 set 移除）
            cnt[to_remove] = 0; 
        }

        // 统计当前 y 能覆盖多少个连续的内层威胁
        long long current_step_ans = 0;
        int edge_ptr = 0;
        const vector<int>& edges = adj[y];
        
        // 从最小的威胁目标开始检查（最内层）
        for (int t : active_targets) {
            // 在 y 的出边中寻找 t
            while (edge_ptr < edges.size() && edges[edge_ptr] < t) {
                edge_ptr++;
            }
            
            // 如果找到了匹配的边 y -> t
            if (edge_ptr < edges.size() && edges[edge_ptr] == t) {
                current_step_ans += cnt[t];
            } else {
                // 如果最内层的威胁没被覆盖，外层的 x 也无法强迫 Tom 移动（因为 Jerry 可以利用这个漏洞赢），
                // 或者说 Tom 对那些 x 必输。
                // 链条断裂，停止计数。
                break;
            }
        }
        
        total_ans += current_step_ans;
    }

    cout << total_ans << "\n";
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}