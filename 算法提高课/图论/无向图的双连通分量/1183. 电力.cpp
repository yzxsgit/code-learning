#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e4 + 10;

vector<int> adj[N];
int dfn[N], low[N], timer;
int num, root;
int n, m;

void tarjan(int u)
{
    dfn[u] = low[u] = ++timer;

    int cnt = 0;
    for (int v : adj[u])
    {
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
            if (dfn[u] <= low[v])
                cnt++;
        }
        else
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (u != root)
        cnt++;

    num = max(num, cnt);
}

void init()
{
    for (int i = 0; i < n; i++)
        adj[i].clear();
    memset(dfn, 0, sizeof dfn);
    memset(low, 0, sizeof low);
    timer = num = 0;
}

void solve()
{
    init();
    
    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    int total = 0;
    for (root = 0; root < n; root++)
        if(!dfn[root])
        {
            total++;
            tarjan(root);
        }

    cout << total + num - 1 << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    while (cin >> n >> m && (n || m))
    {
        solve();
    }
    return 0;
}