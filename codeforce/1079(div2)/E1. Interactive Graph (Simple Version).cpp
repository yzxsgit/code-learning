#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

vector<int> ask(long long k) {
    cout << "? " << k << endl; // endl 会自动 flush
    int q;
    cin >> q;
    
    if (q == -1) {
        exit(0); // 遇到 -1 立即退出，避免 RE/TLE
    }
    
    if (q == 0) {
        return {};
    }
    
    vector<int> path(q);
    for (int i = 0; i < q; ++i) {
        cin >> path[i];
    }
    return path;
}

void solve() {
    int n;
    cin >> n;

    // start_indices[u] 表示以顶点 u 开头的路径在字典序列表中的起始索引 (1-based)
    // start_indices[n+1] 用于辅助计算顶点 n 的路径数量
    vector<long long> start_indices(n + 2);
    start_indices[1] = 1;

    // --- 第一阶段：二分查找确定每个顶点的辖区范围 ---
    
    // 我们需要找到每个 u 的辖区结束位置。
    // 由于字典序特性，以 u 开头的路径是连续的。
    // 我们依次确定 2, 3, ..., n, (n+1) 的起始位置。
    
    long long current_start = 1;
    
    for (int u = 1; u <= n; ++u) 
    {
        long long L = current_start;
        long long R = (1LL << 30); 
        long long ans = L; 

        while (L <= R) 
        {
            long long mid = L + (R - L) / 2;
            vector<int> path = ask(mid);

            if (path.empty()) 
            {
                R = mid - 1;
            } 
            else 
            {
                if (path[0] == u) 
                {
                    ans = mid;
                    L = mid + 1;
                }
                else 
                {
                    R = mid - 1;
                }
            }
        }
        
        start_indices[u + 1] = ans + 1;
        current_start = ans + 1;
    }

    vector<long long> counts(n + 1);
    for (int i = 1; i <= n; ++i) 
    {
        counts[i] = start_indices[i+1] - start_indices[i];
    }

    vector<pair<int, int>> edges;
    
    for (int u = 1; u <= n; ++u) 
    {   
        long long k = start_indices[u] + 1;
        long long limit = start_indices[u+1];
        
        while (k < limit) 
        {
            vector<int> path = ask(k);
            
            int v = path[1];
            edges.push_back({u, v});
            
            // 关键跳跃：
            // 以 u -> v 开头的路径列表形式上是：
            // [u, v]
            // [u, v, x...]
            // ...
            // 这些路径可以通过将 [u] 拼接到所有以 v 开头的路径前面得到。
            // 因此，以 u -> v 开头的路径数量正好等于 counts[v]。
            // 我们跳过这些路径，去寻找 u 的下一条出边。
            k += counts[v];
        }
    }

    cout << "! " << edges.size() << endl;
    for (auto &e : edges) 
    {
        cout << e.first << " " << e.second << endl;
    }
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