#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
using PII = pair<int, int>;

const int N = 1010, inf = 1e9;

vector<vector<PII>> g(N);
int n, m1, m2;

int spfa(int m)
{
    vector<int> dist(n + 1, inf), cnt(n + 1);
    vector<bool> st(n + 1);
    queue<int> q;

    for (int i = 1; i <= m; i++)
    {
        dist[i] = 0;
        st[i] = true;
        q.push(i);
    }

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (auto i : g[t])
        {
            int j = i.first;
            if(dist[j] > dist[t] + i.second)
            {
                dist[j] = dist[t] + i.second;
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= n)
                    return -1;
                if(!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }

    return dist[n] == inf ? -2 : dist[n];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m1 >> m2;

    while (m1--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b)
            swap(a, b);
        g[a].push_back({b, c});
    }

    while (m2--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        if (a > b)
            swap(a, b);
        g[b].push_back({a, -c});
    }

    for (int i = 1; i < n; i++)
        g[i + 1].push_back({i,0});

    if(spfa(n) != -1)
    {
        cout << spfa(1) << '\n';
    }
    else
    {
        puts("-1");
    }

    return 0;
}