#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 510;

vector<PII> adj[N];
int m;
int cur[N];
vector<int> res;
bool used[N];
int degree[N];     

void dfs(int u)
{
    for (int &i = cur[u]; i < adj[u].size();)
    {
        int v = adj[u][i].first, id = adj[u][i].second;
        i++;
        if (used[id]) continue;
        used[id] = true;
        dfs(v);
    }
    res.push_back(u);
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> m;

    for (int i = 1; i <= m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back({b, i});
        adj[b].push_back({a, i});
        degree[a]++;
        degree[b]++;
    }

    for (int i = 1; i <= 500; i++)
        if (!adj[i].empty())
            sort(adj[i].begin(), adj[i].end());

    int start = 1;
    int odd_cnt = 0;
    int first_odd = -1;
    
    int first_nonzero = -1;
    for (int i = 1; i <= 500; i++) {
        if (degree[i] > 0) 
        {
            if (first_nonzero == -1) 
                first_nonzero = i;
            if (degree[i] % 2 == 1) 
            {
                if (first_odd == -1) first_odd = i;
                odd_cnt++;
            }
        }
    }
    if (first_odd != -1) 
    {
        start = first_odd;
    }
    else 
    {
        start = first_nonzero;
    }
    dfs(start);

    reverse(res.begin(), res.end());

    for (int i : res)
        cout << i << '\n';

    return 0;
}