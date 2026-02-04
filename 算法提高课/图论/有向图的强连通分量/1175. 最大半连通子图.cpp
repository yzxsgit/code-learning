#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <set>
#include <unordered_set>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e5 + 10;

vector<int> g[N], adj[N];
int dfn[N], low[N], timer;
int scc_id[N], scc_size[N], scc_count = 0;
stack<int> s;
bool in_stk[N];
int n, m, mod;
int F[N], G[N];

void tarjan(int u)
{
    dfn[u] = low[u] = ++timer;
    s.push(u), in_stk[u] = true;

    for (auto v : adj[u])
    {
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[v], low[u]);
        }
        else if(in_stk[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] ==dfn[u])
    {
        ++scc_count;
        while (true)
        {
            int node = s.top();
            s.pop();
            in_stk[node] = false;
            scc_id[node] = scc_count;
            scc_size[scc_count]++;
            if (node == u) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m >> mod;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i);

    unordered_set<i64> S;
    for (int i = 1; i <= n; i++)
    {
        for (auto j : adj[i])
        {
            int a = scc_id[i], b = scc_id[j];
            i64 hash = 10000000ll * a + b;
            if (a != b && !S.count(hash))
            {
                g[a].push_back(b);
                S.insert(hash);
            }
        }
    }

    for (int i = scc_count; i >= 0; i--)
    {
        if(!F[i])
        {
            F[i] = scc_size[i];
            G[i] = 1;
        }
        for (int j : g[i])
        {
            if(F[j] < F[i] + scc_size[j])
            {
                F[j] = F[i] + scc_size[j];
                G[j] = G[i];
            }
            else if (F[j] == F[i] + scc_size[j])
            {
                G[j] = (G[j] + G[i]) % mod;
            }
        }
    }

    int maxf = 0, sum = 0;

    for (int i = 1; i <= scc_count; i++)
    {
        if (maxf < F[i])
        {
            maxf = F[i];
            sum = G[i];
        }
        else if (maxf == F[i])
            sum = (sum + G[i]) % mod;
    }

    cout << maxf << '\n';
    cout << sum << '\n';

    return 0;
}