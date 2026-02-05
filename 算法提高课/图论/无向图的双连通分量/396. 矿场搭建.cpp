#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = unsigned long long;
using PII = pair<int,int>;

const int N = 1010;

stack<int> s;
vector<int> adj[N];
int dfn[N], low[N], timer;
bool is_cut[N];
int root;
vector<vector<int>> dccs;
int n;

void init(int max_n)
{
    for (int i = 0; i <= max_n; i++)
        adj[i].clear();
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    memset(is_cut, 0, sizeof is_cut);
    timer = 0;
    while (s.size())
        s.pop();
    dccs.clear();
}

void tarjan(int u)
{
    dfn[u] = low[u] = ++timer;
    s.push(u);
    
    if (u == root && adj[u].empty())
    {
        dccs.push_back({u});
        return;
    }

    int cnt = 0;
    for (auto v : adj[u])
    {
        if(!dfn[v])
        {
            cnt++;
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (dfn[u] <= low[v])
            {
                is_cut[u] = true;

                vector<int> tmp;
                while (true)
                {
                    int node = s.top();
                    s.pop();
                    tmp.push_back(node);
                    if (node == v) break;
                }
                tmp.push_back(u);
                dccs.push_back(tmp);
            }
        }
        else 
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (u == root && cnt < 2)
        is_cut[u] = false;
}

int m, T = 1;
void solve()
{
    n = 0;
    vector<PII> edges;
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        edges.push_back({a, b});
        n = max(n, max(a, b));
    }

    init(n);

    for (auto [a, b] : edges)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    for (int i = 1; i <= n; i++)
        if(!dfn[i])
        {
            root = i;
            tarjan(i);
        }

    i64 way = 1;
    int res = 0;

    for (auto dcc : dccs)
    {
        int cnt = 0;
        for (int node : dcc)
            if (is_cut[node])
                cnt++;
                    
        i64 q = dcc.size();
        if (cnt == 0)
        {
            if (q > 1)
            {
                res += 2;
                way *= q * (q - 1) / 2;
            }
            else
            {
                res++;
            }
        }
        else if(cnt == 1)
        {
            res += 1;
            if (q > 1)
                way *= (q - 1);
        }
    }

    cout << "Case " << T << ": " << res << ' ' << way << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    while (cin >> m && m)
    {
        solve();
        T++;
    }
    return 0;
}