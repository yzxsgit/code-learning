#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 4e3 + 10;

vector<PII> adj[N];
vector<int> d(N), res;
int n, m;

void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n + m; i++)
        if(!d[i])
            q.push(i);

    while (q.size())
    {
        int t = q.front();
        q.pop();
        res.push_back(t);

        for (auto [v,w] : adj[t])
            if(--d[v] == 0)
                q.push(v);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        vector<bool> st(n + 1, 0);
        int t;
        cin >> t;
        int start, ed;
        t -= 2;
        cin >> start;
        st[start] = true;
        while (t--)
        {
            int stop;
            cin >> stop;
            st[stop] = true;
        }
        cin >> ed;
        st[ed] = true;
        int ver = n + i;
        for (int j = start; j <= ed; j++)
            if (st[j])
            {
                adj[ver].push_back({j, 1});
                d[j]++;
            }
            else 
            {
                adj[j].push_back({ver, 0});
                d[ver]++;
            }
    }

    topsort();
    
    vector<int> dist(n + m + 1, 0);
    for (int i = 1; i <= n; i++) dist[i] = 1;
    for (int i : res)
        for (auto [j, w] : adj[i])
            dist[j] = max(dist[j], dist[i] + w);

    int ans = 0;
    for (int i = 1; i <= n; i++)
        ans = max(ans, dist[i]);

    cout << ans << '\n';

    return 0;
}