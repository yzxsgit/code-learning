# D. Cost of Tree — 题目解析

---

## 一、题目解析

### 1. 题意理解
给定一棵以节点1为根的 $n$ 个节点的树，每个节点 $i$ 有权值 $a_i$。树的"代价"定义为 $\sum_{u} a_u \cdot d(r, u)$，其中 $d(r,u)$ 是根 $r$ 到 $u$ 的距离（边数）。

对每个节点 $r$（$1 \le r \le n$），考虑以 $r$ 为根的**子树**，可以**至多执行一次操作**：选择子树中 $u \ne r$ 的节点，断开 $u$ 与其父节点的边，然后将 $u$ 接到子树中任意仍与 $r$ 连通的节点 $v$ 上。求操作后子树的最大代价。

### 2. 核心问题
本质上是：**通过移动一棵子树，使得加权深度和最大化**。

移动子树 $u$ 到节点 $v$ 的效果：$u$ 的整棵子树的所有节点深度统一改变。设 $u$ 原来在深度 $dep_u$，移到 $v$ 后深度变为 $dep_v + 1$，则 $u$ 子树中所有节点深度变化 $\Delta = (dep_v + 1) - dep_u$，代价变化 = $\Delta \times \text{sum}(u \text{的子树权值和})$。

为了最大化，我们希望 $\Delta$ 最大 → 让 $v$ 深度尽量大 → 将 $u$ 接到当前树的**最深叶子节点**上。

### 3. 解题思路

使用 DFS 自底向上递归，每个节点维护4个信息（`array<ll, 4>`）：
- `ans[0]`：不使用操作时，以此节点为根的子树代价
- `ans[1]`：使用至多一次操作后的最大子树代价
- `ans[2]`：子树的权值总和
- `ans[3]`：子树的最大深度

**递归合并时**：
1. **不操作的代价**：每个子节点 $c$ 的贡献 = $c$ 的代价 + $c$ 的子树权值和（因为从当前节点看，$c$ 子树所有节点深度都多了1）
2. **操作来自子节点内部**：某个子节点内部已经用了操作 → 取最大增益 `max(sa[1] - sa[0])`
3. **操作是当前层发起**：将某个子树 $c$ 整棵移到"其他子树的最深叶子"上 → 增益 = `maxDepthFromOtherSubtrees × c的子树权值和`

第3点需要枚举每个子树 $c$，计算"排除 $c$ 后的最大深度"（使用最大/次大深度），从而 $O(\text{children})$ 完成。

---

## 二、知识点归类

| 项目         | 内容                     |
| ------------ | ------------------------ |
| **主要算法** | 树形 DP                  |
| **数据结构** | 树、邻接表               |
| **编程技巧** | 最大/次大值维护、DFS递归 |
| **难度等级** | 困难                     |

---

## 三、关键提示点

### 1. 易错点提醒
- 移动子树后，被移动子树内部的**相对结构不变**，只是整体深度偏移
- 需要区分"操作发生在子节点内部"vs"操作发生在当前层"

### 2. 边界条件
- 叶子节点：子树只有1个节点，无法操作，代价=0
- 只有2个子节点时：最大深度和次大深度的维护要正确初始化

### 3. 优化思路
- 维护最大/次大深度避免 $O(k^2)$ 枚举（$k$ 为子节点数）
- 时间复杂度 $O(n)$

### 4. 常见陷阱
- 移动的目标 $v$ 必须在移动后仍然与 $r$ 连通（不能移到断开的那部分）
- `maxDepthFromOtherSubtrees` 需要排除当前子树的深度贡献

---

## 四、代码解析

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

// 返回值: {不操作的代价, 操作后最大代价, 子树权值和, 子树最大深度}
array<ll, 4> func(ll par, ll child, vector<vector<ll>> &a, vector<ll> &v, vector<array<ll, 4>> &ans){
    // 初始化当前节点：代价=0, 操作代价=0, 权值和=v[child], 最大深度=0
    array<ll, 4> currAns = {0, 0, v[child], 0};

    ll maxDepth = 0;        // 所有子树中的最大深度
    ll secondMaxDepth = 0;  // 第二大深度（用于排除某个子树后的最大深度）

    // 记录"操作发生在子节点内部"时的最大增益
    ll maxAnsIncreaseWithOperationUsed = 0;

    for (auto i : a[child])
    {
        if(i != par){
            // 递归处理子节点 i
            array<ll, 4> sa = func(child, i, a, v, ans);

            // 维护最大/次大深度（子树深度+1 = 从当前节点看的深度）
            if (sa[3] + 1 >= maxDepth) {
                secondMaxDepth = maxDepth;
                maxDepth = sa[3] + 1;
            }
            else if (sa[3] + 1 > secondMaxDepth) {
                secondMaxDepth = sa[3] + 1;
            }

            // 记录子节点内部操作的最大增益
            maxAnsIncreaseWithOperationUsed = max(maxAnsIncreaseWithOperationUsed, sa[1] - sa[0]);

            // 合并：不操作代价 += 子树代价 + 子树权值和（深度+1的贡献）
            currAns[0] += sa[0] + sa[2];
            currAns[1] += sa[0] + sa[2];  // 操作代价基础值也先加上
            currAns[2] += sa[2];          // 累加权值和
        }
    }

    // 情况1：操作来自某个子节点内部
    currAns[1] += maxAnsIncreaseWithOperationUsed;
    currAns[3] = maxDepth;

    // 情况2：操作是在当前层发起 —— 将某个子树移到其他子树的最深处
    for (auto i : a[child])
    {
        if(i != par){
            ll cAns = ans[i][0];    // 子树i的不操作代价
            ll cSum = ans[i][2];    // 子树i的权值和
            ll cd = ans[i][3] + 1;  // 子树i从当前节点看的深度

            // 排除子树i后的最大深度
            ll maxDepthFromOtherSubtrees = maxDepth;
            if (cd == maxDepth) {
                maxDepthFromOtherSubtrees = secondMaxDepth;  // 如果i贡献了最大深度，用次大
            }

            // 将子树i移到最深处：增益 = maxDepthFromOtherSubtrees × 子树i的权值和
            // 与当前最优操作方案取max
            currAns[1] = max(currAns[1], currAns[0] + maxDepthFromOtherSubtrees * cSum);
        }
    }

    ans[child] = currAns;  // 保存结果
    return currAns;
}

void solve(){
    ll n, e;
    cin >> n;
    e = n - 1;  // 树有 n-1 条边

    vector<ll> v(n + 1);  // 节点权值（1-indexed）
    for (ll i = 1; i <= n; i++)
    {
        cin >> v[i];
    }

    vector<vector<ll>> a(n + 1);  // 邻接表
    for (ll i = 0; i < e; i++)
    {
        ll u, v;
        cin >> u >> v;
        a[u].push_back(v);
        a[v].push_back(u);
    }

    vector<array<ll, 4>> ans(n + 1);
    
    // 从节点1出发，DFS整棵树
    func(1, 1, a, v, ans);

    // 输出每个节点的子树最大代价
    for (ll i = 1; i <= n; i++)
    {
        cout << ans[i][1] << " ";  // ans[i][1] = 以i为根的子树使用至多一次操作后的最大代价
    }
    cout << "\n";
}

int main() { 
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    ll T = 1;
    cin >> T;
    
    while (T--)
    {
        solve();
    }
    
    return 0;
}
```

### 时间复杂度分析
- DFS 遍历每个节点一次，每个节点处理子节点列表 → 总体 $O(n)$
- 第二个 for 循环再次遍历子节点，但总体仍是 $O(n)$
- **总体**：$O(n)$ per test case

---

## 五、示例推演

以第一个测试用例 `n=5, a=[1,3,2,1,2]` 为例，树结构 `1-2-3-{4,5}`：

**不操作时 $r=1$ 的代价**：$1 \times 0 + 3 \times 1 + 2 \times 2 + 1 \times 3 + 2 \times 3 = 16$

**操作**：将节点5（子树权值和=2）移到节点4下 → 节点5深度从3变为4  
新代价 = $16 + 2 \times 1 = 18$ ✓
