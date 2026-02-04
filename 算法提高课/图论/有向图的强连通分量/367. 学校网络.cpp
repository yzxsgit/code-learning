#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 110;

vector<int> g[N];
int dfn[N], low[N], timer = 0;
int scc_id[N], scc_count = 0;
stack<int> s;
bool in_stk[N];
int din[N], dout[N];
int n;

void tarjan(int u)
{
    dfn[u] = low[u] = ++timer;
    s.push(u);
    in_stk[u] = true;

    for (auto j : g[u])
    {
        if(!dfn[j])
        {
            tarjan(j);
            low[u] = min(low[u], low[j]);
        }
        else if(in_stk[j])
        {
            low[u] = min(low[u], dfn[j]);
        }
    }

    if (dfn[u] == low[u])
    {
        ++scc_count;
        while (true)
        {
            int node = s.top();
            s.pop();
            in_stk[node] = false;
            scc_id[node] = scc_count;
            if (node == u) break;
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int b;
        while (cin >> b && b)
        {
            g[i].push_back(b);
        }
    }

    for (int i = 1; i <= n; i++)
        if(!dfn[i])
            tarjan(i);

    for (int i = 1; i <= n; i++)
    {
        for (auto j : g[i])
        {
            int a = scc_id[i], b = scc_id[j];
            if (a != b)
            {
                din[b]++;
                dout[a]++;
            }
        }
    }

    int a = 0, b = 0;
    for (int i = 1; i <= scc_count; i++)
    {    
        if(din[i] == 0)
            a++;
        if(dout[i] == 0)
            b++;
    }

    cout << a << '\n';

    if(scc_count == 1)
        cout << 0 << '\n';
    else 
        cout << max(a, b) << '\n';

    return 0;
}