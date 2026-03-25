#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int inf = 0x3f3f3f3f;

int n;
vector<vector<PII>> g;
vector<int> dist;
vector<bool> st;

void spfa(int start)
{
    queue<int> q;
    dist[start] = 0;
    q.push(start);
    st[start] = true;

    while (q.size())
    {
        auto u = q.front();
        q.pop();
        st[u] = false;
        int d = dist[u];

        for (auto [v, w] : g[u])
        {
            if (d + w < dist[v])
            {
                dist[v] = d + w;
                if (!st[v])
                {
                    q.push(v);
                    st[v] = true;
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int m, s;
    cin >> n >> m >> s;

    g.resize(n + 1);
    dist.assign(n + 1, inf);
    st.assign(n + 1, false);

    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        g[a].push_back({b, w});
    }

    spfa(s);

    for (int i = 1; i <= n; i++)
        cout << (dist[i] >= inf ? __INT_MAX__ : dist[i]) << (i == n ? '\n' : ' ');
    return 0;
}