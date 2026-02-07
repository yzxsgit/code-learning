#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 2e4 + 10;

vector<PII> adj[N];
int n, m;
int color[N];

bool dfs(int u, int c, int mid)
{
    color[u] = c;

    for (auto [v, w] : adj[u])
    {
        if(w <= mid) continue;
        if(color[v])
        {
            if(color[v] == color[u])
                return false;
        }
        else if (!dfs(v, 3 - c, mid))
        {
            return false;
        }
    }

    return true;
}

bool check(int mid)
{
    memset(color, 0, sizeof color);

    for (int i = 1; i <= n; i++)
        if(!color[i])
            if(!dfs(i,1,mid))
                return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;

    while (m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        adj[a].push_back({b, c});
        adj[b].push_back({a, c});
    }

    int l = 0, r = 1e9;

    while (l < r)
    {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }

    cout << r << '\n';

    return 0;
}