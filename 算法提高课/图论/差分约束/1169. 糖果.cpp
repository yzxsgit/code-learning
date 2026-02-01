#include <iostream>
#include <stack>
#include <vector>

using namespace std;

using PII = pair<int, int>;
using i64 = long long;
const int N = 1e5 + 10, INF = 1e9;
    
vector<int> dist(N,-1e9), cnt(N);
vector<vector<PII>> h(N);
vector<bool> st(N);
int n, m;

bool spfa()
{
    stack<int> q;
    q.push(0);
    dist[0] = 0;
    st[0] = true;

    while (q.size())
    {
        int t = q.top();
        q.pop();
        st[t] = false;

        for (auto i : h[t])
        {
            int j = i.first;
            if(dist[j] < dist[t] + i.second)
            {
                dist[j] = dist[t] + i.second;
                cnt[j] = cnt[t] + 1;
                if (cnt[j] >= n + 1)
                    return false;
                if(!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin >> n >> m;

    for (int i = 1; i <= n; i++)
    {
        h[0].push_back({i, 1});
    }

    while (m--)
    {
        int x, a, b;
        cin >> x >> a >> b;
        if (x == 1)
        {
            h[a].push_back({b, 0});
            h[b].push_back({a, 0});
        }
        else if (x == 2)
        {
            h[a].push_back({b, 1});
        }
        else if (x == 3)
        {
            h[b].push_back({a, 0});
        }
        else if (x == 4)
        {
            h[b].push_back({a, 1});
        }
        else
        {
            h[a].push_back({b, 0});
        }
    }

    if(!spfa())
    {
        puts("-1");
    }
    else
    {
        i64 res = 0;
        for (int i = 1; i <= n; i++)
            res += dist[i];

        cout << res << '\n';
    }

    return 0;
}