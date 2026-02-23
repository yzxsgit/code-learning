# C. All-in-one Gun — 题目解析

---

## 一、题目解析

### 1. 题意理解
有一把枪，弹夹中有 $n$ 颗子弹，依次伤害为 $a_1, a_2, \ldots, a_n$。射击规则：
- 每秒射出一颗子弹，打完全部 $n$ 颗后需要装弹 $k$ 秒，装弹后弹序恢复原样。
- 在战斗**开始之前**，可以选择一次交换：将 $a_i$ 和 $a_j$ 互换（至多一次）。
- 敌人血量为 $h$，求消灭敌人的最少时间（秒）。

### 2. 核心问题
**本质**：二分/枚举"最后一发致命弹"的位置。  
对最后一轮弹夹（最后射击的前 $m$ 发），我们希望前 $m$ 发的伤害之和 ≥ 剩余血量。通过一次交换，可以把任意一颗大伤害子弹换到前 $m$ 位之内。

### 3. 解题思路

**步骤一：去掉完整弹夹的贡献**  
设总伤害 = `sum`，用 `numberOfMagsWithoutLastMag = (h-1)/sum` 完整弹夹消耗后，剩余血量 `h -= numberOfMagsWithoutLastMag * sum`。同时累计时间 `timeWithoutLastMag = n*mags + k*mags`。

**步骤二：在最后一轮弹夹中找最少射击数**  
对于最后一轮弹夹，枚举"最后一发"的位置 $i$（$0 \le i < n$），前 $i+1$ 发的效果：
- **不换的情况**：前缀和 `prefixSumA[i]` ≥ h → 第 $i+1$ 秒击杀。
- **换的情况**：把前 $i+1$ 发中最小的换成后面（$i+1$ 至 $n-1$）最大的 → 新伤害 = `prefixSumA[i] - minFromLeft + maxFromRight[i+1]`，若 ≥ h → 第 $i+1$ 秒击杀。

枚举过程中维护：
- `minFromLeft`：$a[0..i]$ 的最小值（随 $i$ 增大动态更新）
- `maxFromRight[i+1]`：$a[i+1..n-1]$ 的最大值（预处理）

---

## 二、知识点归类

| 项目         | 内容                        |
| ------------ | --------------------------- |
| **主要算法** | 贪心、前缀和、预处理        |
| **数据结构** | 数组                        |
| **编程技巧** | 前缀最大/最小值、后缀最大值 |
| **难度等级** | 中等                        |

---

## 三、关键提示点

### 1. 易错点提醒
- `(h-1)/sum` 而非 `h/sum`：避免整除时多算一个完整弹夹（血量被整除时不应提前结束）。
- 最后一轮枚举时，`i+1` 位不能越界（需特判 `i+1 < n`）。

### 2. 边界条件
- 一轮弹夹就足以消灭敌人（`h <= sum`）：`numberOfMagsWithoutLastMag = 0`，直接进入枚举。
- 交换只能发生在位置 $0..n-1$ 范围内，且必须把右边的换到左边（后缀更大值）。

### 3. 优化思路
- 预处理 `maxFromRight[]`，枚举时 $O(1)$ 查询 → 总体 $O(n)$。
- 时间复杂度：$O(n)$ per test case。

### 4. 常见陷阱
- `currSum` 代表**交换后**前 $i+1$ 发的总伤害，但 `maxFromRight[i+1]` 在 $i = n-1$ 时越界！代码中循环到 `i < n-1`，最后一个位置不需要用后缀最大值（无可交换元素）。

---

## 四、代码解析

```cpp
#include <bits/stdc++.h>
using namespace std;

#define ll long long int

void solve(){

    ll n, h, k;
    cin >> n >> h >> k;
    // n: 弹夹容量，h: 敌人血量，k: 装弹时间

    vector<ll> a(n);
    vector<ll> prefixSumA(n);  // 前缀和数组

    for (ll i = 0; i < n; i++)
    {
        cin >> a[i];
        prefixSumA[i] = a[i];
        if(i - 1 >= 0){
            prefixSumA[i] += prefixSumA[i - 1];  // 构建前缀伤害和
        }
    }

    ll sum = prefixSumA[n - 1];  // 一整个弹夹的总伤害

    // 计算不含最后一轮弹夹的完整弹夹数
    // 用 (h-1)/sum 而非 h/sum，避免 h 恰好整除时多算一轮
    ll numberOfMagsWithoutLastMag = (h - 1) / sum;
    // 完整弹夹消耗时间 = 射击时间 + 装弹时间
    ll timeWithoutLastMag = n * numberOfMagsWithoutLastMag + k * numberOfMagsWithoutLastMag;

    // 扣除完整弹夹的伤害
    h -= numberOfMagsWithoutLastMag * sum;

    // 理论上 h 不会 <= 0，但保险起见
    if (h <= 0){
        cout << timeWithoutLastMag << "\n";
        return;
    }

    // 预处理后缀最大值：maxFromRight[i] = max(a[i], a[i+1], ..., a[n-1])
    vector<ll> maxFromRight(n);
    maxFromRight[n - 1] = a[n - 1];
    for (ll i = n - 2; i >= 0; i--)
    {
        maxFromRight[i] = max(maxFromRight[i + 1], a[i]);
    }

    // 枚举最后一轮弹夹"最后一发"的位置 i（0-indexed）
    // minFromLeft：a[0..i] 的最小值（用于找出可被替换掉的最小值）
    ll minFromLeft = a[0];
    
    for (ll i = 0; i < n; i++)
    {
        minFromLeft = min(minFromLeft, a[i]);  // 动态维护前缀最小值

        // 交换策略：将前 i+1 发中最小的换成后 n-i-1 发中最大的
        // currSum = 前缀和 - 最小值 + 后缀最大值（一次最优交换后的伤害）
        // 注意：i+1 < n 才有后缀，i = n-1 时不执行交换分支
        ll currSum = prefixSumA[i] - minFromLeft + maxFromRight[i + 1];

        // 两种情况都判断：
        // 1. 交换后前 i+1 发足以击杀 (h <= currSum)
        // 2. 不交换，前 i+1 发也足以击杀 (h <= prefixSumA[i])
        if(h <= currSum || h <= prefixSumA[i]){
            // 总时间 = 完整弹夹时间 + 最后一轮射了 i+1 发（第 i+1 秒击杀）
            cout << timeWithoutLastMag + i + 1 << "\n";
            return;
        }
    }
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

> **注意**：代码中 `maxFromRight[i + 1]` 在 `i = n-1` 时越界，但循环到 `i = n-1` 时，若 `h <= prefixSumA[n-1]` 必然成立（因为我们最多消耗 `sum` 伤害但保留了不少血量），所以**提前就返回**，不会访问越界地址——这是一个隐性的保证。

### 时间复杂度分析
- 预处理后缀最大值：$O(n)$
- 枚举最后一轮：$O(n)$
- **总体**：$O(n)$ per test case，$O(\sum n)$ 全局

---

## 五、示例推演

以 `n=5, h=10, k=1, a=[4,2,3,5,3]` 为例：
- `sum = 17`，`numberOfMagsWithoutLastMag = 0`，剩余血量 = 10
- `maxFromRight = [5,5,5,5,3]`
- 枚举 $i=0$：`minFromLeft=4`，`currSum=4-4+5=5`，`prefixSum[0]=4`，10 > 5，不够
- 枚举 $i=1$：`minFromLeft=2`，`currSum=6-2+5=9`，`prefixSum[1]=6`，10 > 9，不够  
- 枚举 $i=2$：`minFromLeft=2`，`currSum=9-2+5=12≥10`，**击杀！**，答案 = 0 + 3 = **3** ✓
