#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 5010, M = 10010;

int h[N], e[M], ne[M], idx = 0;
void add(int a, int b)
{
    e[idx] = b, ne[idx] = h[a], h[a] = idx++;
}

int dfn[N], low[N], timer = 0;
int ebcc_id[N], ebcc_cnt = 0;
stack<int> s;
bool is_brigde[M];
int n, m;
int d[N];

void tarjan(int u, int from)
{
    dfn[u] = low[u] = timer++;
    s.push(u);

    for (int i = h[u]; ~i; i = ne[i])
    {
        int j = e[i];
        if (i == (from ^ 1)) continue;
        if (!dfn[j])
        {
            tarjan(j, i);
            low[u] = min(low[j], low[u]);
            if (dfn[u] < low[j])
                is_brigde[i] = is_brigde[i ^ 1] = true;
        }
        else 
        {
            low[u] = min(low[u], dfn[j]);
        }
    }

    if (dfn[u] == low[u])
    {
        ebcc_cnt++;
        while (true)
        {
            int node = s.top();
            s.pop();
            ebcc_id[node] = ebcc_cnt;
            if (node == u) break;
        }
    }
}

int main()
{
    memset(h, -1, sizeof h);
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        add(a, b), add(b, a);
    }

    tarjan(1, -1);

    for (int i = 0; i < idx; i++)
        if(is_brigde[i])
        {
            int j = e[i];
            d[ebcc_id[j]]++;
        }

    int cnt = 0;
    for (int i = 1; i <= n; i++)
        if(d[i] == 1)
            cnt++;

    cout << (cnt + 1) / 2 << '\n';

    return 0;
}