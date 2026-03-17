#include <bits/stdc++.h>
using namespace std;

const int MAXN = 505;
// row_bs[i]: 第i行的bitset，表示节点i能到达哪些节点
// col_bs[j]: 第j列的bitset，表示哪些节点能到达节点j
bitset<MAXN> row_bs[MAXN], col_bs[MAXN];

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        vector<string> s(n);
        for (int i = 0; i < n; i++)
        {
            cin >> s[i];
            row_bs[i].reset(); // 清空bitset
            col_bs[i].reset();
        }

        bool valid = true;

        // ========== 第一步：检查自反性 ==========
        // 每个节点必须能到达自身，即 s[i][i] = '1'
        for (int i = 0; i < n && valid; i++)
            if (s[i][i] != '1')
                valid = false;

        // ========== 第二步：检查反对称性 ==========
        // 对于 i ≠ j，不能同时 s[i][j]=1 且 s[j][i]=1
        // 因为树上唯一路径只能有一个方向
        for (int i = 0; i < n && valid; i++)
            for (int j = i + 1; j < n && valid; j++)
                if (s[i][j] == '1' && s[j][i] == '1')
                    valid = false;

        if (!valid)
        {
            cout << "No\n";
            continue;
        }

        // ========== 构建行/列 bitset ==========
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (s[i][j] == '1')
                {
                    row_bs[i].set(j); // 节点i可达节点j
                    col_bs[j].set(i); // 节点i可达节点j（列视角）
                }

        // ========== 第三步：检查传递性 ==========
        // 若 s[i][j]=1，则 j 能到达的所有节点，i 也必须能到达
        // 即 row[j] 必须是 row[i] 的子集
        // 用bitset操作：(row[j] & row[i]) == row[j]
        for (int i = 0; i < n && valid; i++)
            for (int j = 0; j < n && valid; j++)
                if (i != j && s[i][j] == '1')
                    if ((row_bs[j] & row_bs[i]) != row_bs[j])
                        valid = false;
        // 时间复杂度：O(n^2 × n/64) = O(n^3/64)

        if (!valid)
        {
            cout << "No\n";
            continue;
        }

        // ========== 第四步：计算传递归约 ==========
        // 边 (u,v) 在归约中，当且仅当：
        //   s[u][v] = 1，且不存在中间节点 w (w≠u, w≠v)
        //   使得 s[u][w]=1 且 s[w][v]=1
        // 用bitset：检查 row[u] & col[v] 去掉 u,v 本身后是否为空
        vector<pair<int, int>> edges;
        for (int u = 0; u < n; u++)
        {
            for (int v = 0; v < n; v++)
            {
                if (u != v && s[u][v] == '1')
                {
                    // inter = 所有满足"u可达w且w可达v"的中间节点集合
                    bitset<MAXN> inter = row_bs[u] & col_bs[v];
                    inter.reset(u); // 排除u本身
                    inter.reset(v); // 排除v本身
                    if (inter.none())
                    {
                        // 没有中间节点 → 这是一条直接边（树边）
                        edges.push_back({u, v});
                    }
                }
            }
        }
        // 时间复杂度：O(n^2 × n/64) = O(n^3/64)

        // ========== 第五步：验证边数 ==========
        // 树恰好有 n-1 条边
        if ((int)edges.size() != n - 1)
        {
            cout << "No\n";
            continue;
        }

        // ========== 第六步：验证连通性 ==========
        // 底层无向图必须连通（n-1条边 + 连通 = 树）
        vector<vector<int>> adj(n);
        for (auto [u, v] : edges)
        {
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int cnt = 1;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();
            for (int nb : adj[node])
            {
                if (!visited[nb])
                {
                    visited[nb] = true;
                    cnt++;
                    q.push(nb);
                }
            }
        }

        if (cnt != n)
        {
            cout << "No\n";
            continue;
        }

        // ========== 输出结果 ==========
        cout << "Yes\n";
        for (auto [u, v] : edges)
            cout << u + 1 << " " << v + 1 << "\n";
        // 注意：输出时节点编号从1开始
    }

    return 0;
}