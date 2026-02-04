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

vector<int> g[N];

int n, m;
int dfn[N], low[N], timer = 0;
int scc_id[N], scc_size[N], scc_count = 0;
stack<int> s;
bool in_stk[N];
int dout[N];

void tarjan(int u)
{
    dfn[u] = low[u] = ++timer;
    s.push(u);
    in_stk[u] = true;

    for (auto v : g[u])
    {
        if(!dfn[v])
        {
            tarjan(v);
            low[u] = min(low[u], low[v]);
        }
        else if(in_stk[v])
        {
            low[u] = min(low[u], dfn[v]);
        }
    }

    if (low[u] == dfn[u])
    {
        scc_count++;
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

    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
    }

    for (int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i);

    for (int i = 1; i <= n; i++)
        for (auto j : g[i])
        {
            int a = scc_id[i], b = scc_id[j];
            if (a != b) dout[a]++;
        }

    int zero = 0, sum = 0;

    for (int i = 1; i <= scc_count; i++)
    {
        if(!dout[i])
        {
            zero++;
            sum += scc_size[i];
            if (zero > 1)
            {
                sum = 0;
                break;
            }
        }
    }
    
    cout << sum << '\n';
    
    return 0;
}