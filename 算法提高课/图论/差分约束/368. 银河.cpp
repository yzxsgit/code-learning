#include <iostream>
#include <stack>
#include <vector>

using namespace std;

using PII = pair<int, int>;
using i64 = long long;
const int N = 1e5 + 10, INF = 1e9;
    
vector<PII> h[N], g[N];
int n, m;
int dfn[N], low[N], timer = 0;
int scc_id[N], scc_size[N], scc_count = 0;
stack<int> s;
bool in_stack[N];
int dist[N];

void tarjan(int u)
{
    dfn[u] = low[u] = ++timer;
    s.push(u), in_stack[u] = true;

    for (auto [j, w] : h[u])
    {
        if(!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if(in_stack[j])
        {
            low[u] = min(low[u], dfn[j]);
        }
    }

    if (dfn[u] == low[u])
    {
        scc_count++;
        while (true)
        {
            int node = s.top();
            s.pop();
            in_stack[node] = false;
            scc_id[node] = scc_count;
            scc_size[scc_count]++;
            if (node == u) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        h[0].push_back({i, 1});
    }

    while (m--)
    {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1)
        {
            h[a].push_back({b, 0});
            h[b].push_back({a, 0});
        }
        else if (x == 2)
        {
            h[a].push_back({b, 1});
        }
        else if (x == 3)
        {
            h[b].push_back({a, 0});
        }
        else if (x == 4)
        {
            h[b].push_back({a, 1});
        }
        else
        {
            h[a].push_back({b, 0});
        }
    }

    tarjan(0);

    bool success = true;
    for (int i = 0; i <= n; i++)
    {
        for (auto [j, w] : h[i])
        {
            int a = scc_id[i], b = scc_id[j];
            if (a == b)
            {
                if(w > 0)
                {
                    success = false;
                    break;
                }
            }
            else 
            {
                g[a].push_back({b, w});
            }
        }

        if (!success) break;
    }

    if (!success)
    {
        cout << -1 << '\n';
    }
    else 
    {
        for (int i = scc_count; i >= 0; i--)
            for (auto [j, w] : g[i])
                dist[j] = max(dist[j], w + dist[i]);

        i64 res = 0;
        for (int i = 1; i <= scc_count; i++)
            res += (i64)scc_size[i] * dist[i];

        cout << res << '\n';
    }

    return 0;
}