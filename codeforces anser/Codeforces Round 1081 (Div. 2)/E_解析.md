# E. Swap to Rearrange — 题目解析

---

## 一、题目解析

### 1. 题意理解
给定长度为 $n$ 的两个数组 $a$ 和 $b$。每次操作：选一个下标 $i$，交换 $a_i$ 和 $b_i$。每个下标最多选一次。  
目标：使操作后的 $a$ 是 $b$ 的一个**排列**（即 $a$ 和 $b$ 包含相同的多重集元素）。

### 2. 核心问题
每个位置 $i$ 有一对 $(a_i, b_i)$。交换操作让这对变为 $(b_i, a_i)$。最终要求 $a$ 的多重集 = $b$ 的多重集。

**关键观察**：将每个位置 $i$ 看成一条**边** $a_i \leftrightarrow b_i$。选择交换位置 $i$ 相当于给这条边一个方向（$a_i \to b_i$ 或 $b_i \to a_i$）。最终，对每个值 $v$，流入 $a$ 的数量 = 流入 $b$ 的数量。

这等价于：对每个值 $v$，以 $v$ 为端点的边数必须为**偶数**（否则无解）。  
选择交换与否对应于图中每条边的**欧拉回路方向选择**问题。

### 3. 解题思路

1. **建图**：对每个位置 $i$，连边 $a_i \leftrightarrow b_i$，边的权重/标号为 $i$
2. **判断可行性**：若某个节点的度数为奇数，则无解（无法找到欧拉回路/欧拉路径使得每个节点出入度相等）
3. **求解**：对每个连通分量找欧拉回路。DFS 遍历边，根据边的方向决定是否交换。如果边从 $a_i$ 出发到 $b_i$，不交换；如果从 $b_i$ 出发到 $a_i$，则交换位置 $i$。

代码使用了一种高效的 DFS 欧拉回路实现（类似 Hierholzer 算法）：
- 邻接表存 `(对端节点, 边编号 w)`
- 遍历时标记边为已访问 (`vst[w] = true`)
- 如果当前节点 = `a[w]`（即这条边从 a 端出发），标记 `ans[w] = true`（需要交换）

---

## 二、知识点归类

| 项目         | 内容                              |
| ------------ | --------------------------------- |
| **主要算法** | 图论、欧拉回路                    |
| **数据结构** | 邻接表、DFS                       |
| **编程技巧** | Hierholzer 算法变体、边的方向确定 |
| **难度等级** | 困难                              |

---

## 三、关键提示点

### 1. 易错点提醒
- 建图时 $a_i = b_i$ 的边是**自环**，自环不影响度数奇偶性，但需要正确处理
- 边的访问标记是**边级别**（`vst[w]`），不是节点级别

### 2. 边界条件
- 如果 $a$ 已经是 $b$ 的排列，输出 0 次操作
- $n$ 可达 $10^6$，需要高效的欧拉回路算法

### 3. 优化思路
- 使用 `pop_back()` 删除已处理的边，避免重复遍历 → $O(m)$ 总时间
- 时间复杂度 $O(n)$

### 4. 常见陷阱
- `adj[i].size()&1` 用位运算判断度数奇偶，注意 `&` 的优先级
- DFS 中 `node == a[w]` 的判断决定交换方向，不能搞反

---

## 四、代码解析

```cpp
#include <bits/stdc++.h>
using namespace std;

int a[1000005];    // 数组 a
int b[1000005];    // 数组 b
vector<pair<int,int>> adj[1000005];  // 邻接表：adj[v] = {(对端节点, 边编号)}
bool vst[1000005]; // 边的访问标记（以位置编号 w 为索引）
bool ans[1000005]; // ans[w] = true 表示位置 w 需要交换

// DFS 遍历欧拉回路
// 从节点 node 出发，沿未访问的边前进
void dfs(int node) {
    while (adj[node].size()) {
        auto [it, w] = adj[node].back();  // 取出最后一条边：(对端节点 it, 边编号 w)
        adj[node].pop_back();              // 从邻接表中移除（避免重复）
        if (vst[w]) continue;              // 如果边 w 已被另一端访问过，跳过
        vst[w] = true;                     // 标记边 w 已访问
        dfs(it);                           // 递归访问对端节点
        // 回溯时确定方向：
        // 如果当前 node 是这条边在 a 中的值，说明从 a 端出发
        // 意味着 a[w] 留在 a、b[w] 留在 b → 需要交换（ans[w] = true）
        if (node == a[w]) ans[w] = true;
        else ans[w] = false;               // 否则不交换
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int tt;
    cin >> tt;
    while (tt--) {
        int n;
        cin >> n;
        for (int i = 1; i <= n; ++i) {
            cin >> a[i];
        }
        for (int i = 1; i <= n; ++i) {
            cin >> b[i];
        }
        // 清空邻接表和访问标记
        for (int i = 1; i <= n; ++i) {
            adj[i].clear();
            vst[i] = false;
        }
        // 建图：位置 i 的边连接值 a[i] 和 b[i]
        for (int i = 1; i <= n; ++i) {
            adj[a[i]].emplace_back(b[i], i);  // 从 a[i] 到 b[i]，边编号 i
            adj[b[i]].emplace_back(a[i], i);  // 从 b[i] 到 a[i]，边编号 i（无向边）
        }
        // 检查每个节点度数是否为偶数
        bool check = true;
        for (int i = 1; i <= n; ++i) {
            if (adj[i].size() & 1) check = false;  // 度数为奇 → 无解
        }
        if (!check) {
            cout << -1 << '\n';
            continue;
        }
        // 对所有节点 DFS 寻找欧拉回路
        for (int i = 1; i <= n; ++i) {
            dfs(i);
        }
        // 收集需要交换的位置
        vector<int> res;
        for (int i = 1; i <= n; ++i) {
            if (ans[i]) res.push_back(i);
        }
        cout << res.size() << '\n';
        for (auto it : res) {
            cout << it << ' ';
        }
        cout << '\n';
    }
    return 0;
}
```

### 时间复杂度分析
- 建图：$O(n)$
- DFS 欧拉回路：每条边访问恰好一次 → $O(n)$
- **总体**：$O(n)$ per test case，$O(\sum n)$ 全局，满足 $\sum n \le 10^6$

---

## 五、示例推演

以 `n=4, a=[1,2,2,4], b=[3,1,4,3]` 为例：

**建图**：
- 位置1: 边 1↔3
- 位置2: 边 2↔1
- 位置3: 边 2↔4
- 位置4: 边 4↔3

度数：1→2, 2→2, 3→2, 4→2（全偶✓）

**DFS 结果**：位置3和4需要交换  
交换后 $a=[1,2,4,3]$，$b=[3,1,2,4]$ → $a$ 是 $b$ 的排列 ✓
