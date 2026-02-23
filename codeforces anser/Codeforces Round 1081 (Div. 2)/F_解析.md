# F. Fish Fight — 题目解析

---

## 一、题目解析

### 1. 题意理解
池塘中有 $n$ 条鱼排成一行。每条鱼 $i$ 有：
- **体型** $a_i$：决定它能不能吃掉邻居
- **增长值** $b_i$：吃掉它的鱼体型增加 $b_i$

Alice 选鱼 $x$，Bob 选鱼 $y$，双方轮流行动（Alice先手）：
- 当前回合鱼的体型 ≥ 相邻鱼的体型 → 吃掉它（多个可选则**随机等概率**选一个），体型增加被吃鱼的 $b$ 值
- 如果**不能**吃任何相邻鱼 → 被邻居们吃掉，立刻输

Alice 的鱼被吃则 Alice 输，Bob 的鱼被吃则 Bob 输。求 Alice 获胜的**概率**（模 $10^9+7$）。

### 2. 核心问题
这是一个带**概率**的**区间 DP** 问题。两条鱼各自从自己的位置向外扩展"领地"，吃掉相邻的鱼。由于随机选择方向，需要计算所有可能路径的概率总和。

### 3. 解题思路

**预处理**：保证 $x < y$（若不是则翻转数组）。设 Alice 的鱼在 Bob 左边。

**三个 DP**：

1. **`adp[l][r]`**：Alice 的鱼从位置 $x$ 出发，独自扩展到区间 $[l, r]$ 的概率（不碰到 Bob）
2. **`bdp[l][r]`**：Bob 的鱼从位置 $y$ 出发，独自扩展到区间 $[l, r]$ 的概率（不碰到 Alice）
3. **`dp[l][r]`**：Alice 和 Bob 的鱼相邻（中间无其他鱼），共同占据区间 $[l, r]$ 时的 Alice 获胜概率

**`adp` 转移**（`bdp` 类似）：
- `adp[l][r]` 可以从 `adp[l][r-1]`（向右吃）或 `adp[l+1][r]`（向左吃）转移
- 如果两边都能吃 → 各 $\frac{1}{2}$ 概率 → 乘以 `bexpo(2, mod-2)`（2的模逆元）

**`dp` 转移**（Alice 和 Bob 相遇后的对决）：
- 根据奇偶判断当前是谁的回合
- Alice 回合：可能吃掉左边的鱼或吃掉中间"墙"（Alice 和 Bob 之间的边界鱼）
- Bob 回合：类似

**Alice 获胜条件**：
- 情况1：Bob 的鱼被困住（`bdp[l][r]` 区间内无法继续）且 Alice 已清理完左边
- 情况2：Alice 和 Bob 相遇后，Alice 直接吃掉 Bob 或 Bob 无法移动

---

## 二、知识点归类

| 项目         | 内容                             |
| ------------ | -------------------------------- |
| **主要算法** | 区间 DP、概率 DP                 |
| **数据结构** | 二维数组、前缀和                 |
| **编程技巧** | 模逆元（费马小定理）、前缀和优化 |
| **难度等级** | 困难（竞赛 Hard）                |

---

## 三、关键提示点

### 1. 易错点提醒
- 模运算必须在每一步都取模，避免溢出
- Alice 和 Bob 的 $b$ 值设为 0（`b[x]=b[y]=0`），因为主角鱼不会被吃（被吃就输了）

### 2. 边界条件
- 当 $n=2$ 时直接比较 Alice 和 Bob 的体型
- `l=0` 或 `r=n-1` 时的边界判断（是否有外侧邻居）

### 3. 优化思路
- 前缀和 `pb` 快速计算区间内 $b$ 值之和 → 快速算鱼的当前体型
- `asum` 数组用前缀和优化 "固定区间大小，最大右端点" 的查询

### 4. 常见陷阱
- `bexpo(2, mod-2)` 是 $\frac{1}{2} \mod (10^9+7)$ = `500000004`
- 翻转数组后 $x, y$ 的重新映射不能出错

---

## 四、代码解析

```cpp
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
#define FOR(i,a,b) for (int i = (a); i < (b); ++i)
#define F0R(i,a) FOR(i,0,a)
#define int long long       // 全局使用 long long
#define vt vector
const ll mod = 1000000007;  // 模数

// 快速幂：计算 b^e % mod
// 用于求模逆元：a^(-1) ≡ a^(mod-2) (mod p)，费马小定理
int bexpo(int b, int e) {
    int ans = 1;
    while(e) {
        if(e&1) ans=ans*b%mod;  // 当前位为1，乘入结果
        e>>=1;                   // 右移
        b=b*b%mod;               // 底数平方
    }
    return ans;
}

signed main() {
    ios_base::sync_with_stdio(false); 
    cin.tie(0);

    int t;
    cin >> t;
    while(t--) {
        int n,x,y;
        cin >> n >> x >> y;
        x--; y--;  // 转为 0-indexed
        vt<int> a(n), b(n);
        F0R(i, n) cin >> a[i];   // 读入体型
        F0R(i, n) cin >> b[i];   // 读入增长值

        // 保证 x < y（Alice 在 Bob 左边），否则翻转数组
        if(x>y) {
            reverse(begin(a),end(a));
            reverse(begin(b),end(b));
            x=n-x-1;
            y=n-y-1;
        }

        // Alice 和 Bob 的鱼不会被吃（被吃就输了），所以它们的 b 值无意义，设为 0
        b[x]=b[y]=0;

        // 前缀和：pb[i+1] = b[0] + b[1] + ... + b[i]
        // 用于快速计算鱼吃掉区间 [l,r] 后体型增长的总量
        vt<int> pb(n+1);
        F0R(i, n) pb[i+1]=pb[i]+b[i];

        // ========== adp: Alice 独自扩展的概率 DP ==========
        // adp[l][r] = Alice 的鱼占据区间 [l,r] 的概率（不碰到 Bob）
        vt<vt<int>> adp(n, vt<int>(n));
        adp[x][x]=1;  // 初始状态：Alice 只占自己的位置，概率 1

        FOR(d, 1, n) {           // d = 区间长度 - 1
            FOR(r, d, n) {       // 枚举右端点
                int l = r-d;     // 左端点
                if(x<l || x>r) continue;      // Alice 必须在区间内
                if(y>=l && y<=r) continue;     // Bob 不能在区间内（独自扩展）

                // Alice 当前体型 = 初始 a[x] + 吃掉区间内其他鱼的 b 值
                int size_without_r = a[x]+pb[r]-pb[l];  // 不含 r 位置的体型

                if(size_without_r<a[r]) continue;  // 吃不了右边的鱼，无法扩展到 r

                // 从 adp[l][r-1] 转移（向右吃了鱼 r）
                if(l!=0 && size_without_r>=a[l-1]) {
                    // 左边也能吃 → 1/2 概率向右
                    adp[l][r]+=adp[l][r-1]*bexpo(2, mod-2);
                } else {
                    // 只能向右 → 概率 1
                    adp[l][r]+=adp[l][r-1];
                }
                adp[l][r]%=mod;

                // 从 adp[l+1][r] 转移（向左吃了鱼 l）
                int size_without_l = a[x]+pb[r+1]-pb[l+1];
                if(size_without_l<a[l]) continue;  // 吃不了左边的鱼

                if(r!=n-1 && size_without_l>=a[r+1]) {
                    // 右边也能吃 → 1/2 概率向左
                    adp[l][r]+=adp[l+1][r]*bexpo(2, mod-2);
                } else {
                    // 只能向左 → 概率 1
                    adp[l][r]+=adp[l+1][r];
                }
                adp[l][r]%=mod;
            }
        }

        // ========== bdp: Bob 独自扩展的概率 DP（结构同 adp）==========
        vt<vt<int>> bdp(n, vt<int>(n));
        bdp[y][y]=1;
        FOR(d, 1, n) {
            FOR(r, d, n) {
                int l = r-d;
                if(y<l || y>r) continue;
                if(x>=l && x<=r) continue;
                int size_without_r = a[y]+pb[r]-pb[l];
                if(size_without_r<a[r]) continue;
                if(l!=0 && size_without_r>=a[l-1]) {
                    bdp[l][r]+=bdp[l][r-1]*bexpo(2, mod-2);
                } else {
                    bdp[l][r]+=bdp[l][r-1];
                }
                bdp[l][r]%=mod;
                int size_without_l = a[y]+pb[r+1]-pb[l+1];
                if(size_without_l<a[l]) continue;
                if(r!=n-1 && size_without_l>=a[r+1]) {
                    bdp[l][r]+=bdp[l+1][r]*bexpo(2, mod-2);
                } else {
                    bdp[l][r]+=bdp[l+1][r];
                }
                bdp[l][r]%=mod;
            }
        }

        // ========== asum: adp 的前缀和，优化查询 ==========
        // asum[diff][r] = sum of adp[l][r] where r-l == diff, for r' <= r
        // 用于快速查询"Alice 占据长度为 diff+1 的区间，右端点 ≤ r"的概率总和
        vt<vt<int>> asum(n, vt<int>(n));
        F0R(l, n) FOR(r, l, n) {
            asum[r-l][r]=adp[l][r];
        }
        FOR(diff, 0, n) {
            FOR(mxr, 1, n) {
                asum[diff][mxr]+=asum[diff][mxr-1];
                asum[diff][mxr]%=mod;
            }
        }

        int ans = 0;

        // ========== 情况 1：Bob 被困住，Alice 未见到 Bob ==========
        // Bob 占据 [l,r] 且两边都吃不了 → Bob 被邻居吃掉 → Alice 赢
        // 需要 Alice 已经清理了 [0, l-2] 范围
        FOR(l, 2, n) {
            FOR(r, l, n) {
                int bsz = a[y]+pb[r+1]-pb[l];  // Bob 的当前体型
                if(l!=0 && bsz>=a[l-1]) continue;  // Bob 能吃左边 → 没被困
                if(r!=n-1 && bsz>=a[r+1]) continue; // Bob 能吃右边 → 没被困
                // Alice 占据了左边长度为 r-l+2 的区间，右端点 ≤ l-2
                ans+=asum[r-l+1][l-2]*bdp[l][r];
                ans%=mod;
            }
        }

        // ========== dp: Alice 和 Bob 相遇后的对决 DP ==========
        // dp[l][r] = Alice 和 Bob 共同占据 [l,r]，它们相邻，Alice 获胜的概率
        vt<vt<int>> dp(n, vt<int>(n));

        // 初始状态：Alice 和 Bob 相邻（y == x+1）
        if(y==x+1) {
            dp[x][y]=1;
        }

        FOR(diff, y-x, n) {
            FOR(r, y, n) {
                int l = r-diff;
                if(x<l || x>r || y<l || y>r || l<0 || r>=n) continue;

                // aend = Alice 控制区域的右边界（Alice 和 Bob 的分界线）
                int aend = (l+r)/2;

                if(l%2==r%2) {
                    // 区间长度为奇数 → 上一步是 Alice 的回合
                    // Alice 可能：(1) 从 dp[l+1][r] 吃了左边鱼 l
                    //            (2) 从分开状态合并（Alice 吃了"墙"aend）
                    int asz = a[x]+pb[aend+1]-pb[l+1], bsz = a[y]+pb[r+1]-pb[aend+1];
                    if(asz>=a[l]) {
                        if(asz>=bsz) {
                            // Alice 也能吃 Bob → 1/2 概率向左
                            dp[l][r]+=dp[l+1][r]*bexpo(2, mod-2);
                            dp[l][r]%=mod;
                        } else {
                            dp[l][r]+=dp[l+1][r];
                            dp[l][r]%=mod;
                        }
                    }
                    if(aend!=0) {
                        // Alice 从独自的 adp 和 Bob 从独自的 bdp 合并
                        int chance = adp[l][aend-1]*bdp[aend+1][r]%mod;
                        asz = a[x]+pb[aend]-pb[l];
                        if(asz>=a[aend]) {
                            if(l!=0 && asz>=a[l-1]) {
                                dp[l][r]+=chance*bexpo(2, mod-2);
                                dp[l][r]%=mod;
                            } else {
                                dp[l][r]+=chance;
                                dp[l][r]%=mod;
                            }
                        }
                    }
                } else {
                    // 区间长度为偶数 → 上一步是 Bob 的回合
                    int asz = a[x]+pb[aend+1]-pb[l], bsz = a[y]+pb[r]-pb[aend+1];
                    if(bsz>=a[r]) {
                        if(bsz>=asz) {
                            dp[l][r]+=dp[l][r-1]*bexpo(2, mod-2);
                            dp[l][r]%=mod;
                        } else {
                            dp[l][r]+=dp[l][r-1];
                            dp[l][r]%=mod;
                        }
                    }
                    if(aend+2<n) {
                        int chance = adp[l][aend]*bdp[aend+2][r]%mod;
                        bsz = a[y]+pb[r+1]-pb[aend+2];
                        if(bsz>=a[aend+1]) {
                            if(r!=n-1 && bsz>=a[r+1]) {
                                dp[l][r]+=chance*bexpo(2, mod-2);
                                dp[l][r]%=mod;
                            } else {
                                dp[l][r]+=chance;
                                dp[l][r]%=mod;
                            }
                        }
                    }
                }

                // 计算当前状态 dp[l][r] 对最终答案的贡献
                int asz = a[x]+pb[aend+1]-pb[l], bsz = a[y]+pb[r+1]-pb[aend+1];
                if(l%2==r%2) {
                    // Bob 的回合，Bob 被困
                    if(bsz<asz) {
                        if(r==n-1 || a[r+1]>bsz) {
                            ans+=dp[l][r];
                            ans%=mod;
                        }
                    }
                } else {
                    // Alice 的回合，Alice 直接吃 Bob
                    if(asz>=bsz) {
                        if(l!=0 && asz>=a[l-1]) {
                            ans+=bexpo(2, mod-2)*dp[l][r];
                            ans%=mod;
                        } else {
                            ans+=dp[l][r];
                            ans%=mod;
                        }
                    }
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
```

### 时间复杂度分析
- `adp`, `bdp`, `dp` 均为 $O(n^2)$ 状态，每个状态 $O(1)$ 转移
- `asum` 的构建：$O(n^2)$
- **总体**：$O(n^2)$ per test case，$O(\sum n^2)$ 全局  
  由于 $\sum n \le 3000$，最坏情况 $n=3000$ 的单个用例约 $9 \times 10^6$，在4秒时限内可行

---

## 五、示例推演

以 `n=2, x=1, y=2, a=[2,1], b=[1,1]` 为例：
- Alice 体型 2 ≥ Bob 体型 1 → Alice 直接吃掉 Bob → Alice 赢，概率 = **1** ✓

以 `n=3, x=2, y=3, a=[1,4,4], b=[0,1,1]` 为例：
- Alice 鱼(体型4)两边都能吃：
  - 吃鱼3(Bob) → Alice 赢（概率 1/2）
  - 吃鱼1 → Alice 体型 4+0=4，Bob 体型 4 ≥ 4 → Bob 吃 Alice → Alice 输（概率 1/2）
- 总概率 = **1/2** = `500000004` (mod $10^9+7$) ✓
