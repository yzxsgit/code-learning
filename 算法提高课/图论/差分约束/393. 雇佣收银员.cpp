#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;
const int N = 25, M = 100, INF = 0x3f3f3f3f;

vector<int> num(N), r(N);

bool spfa(int c)
{
    vector<vector<PII>> g(N);
    g[0].push_back({24, c});
    g[24].push_back({0, -c});
    for (int i = 1; i <= 7; i++)
        g[i + 16].push_back({i, r[i] - c});
    for (int i = 8; i <= 24; i++)
        g[i - 8].push_back({i, r[i]});
    for (int i = 1; i <= 24; i++)
    {
        g[i].push_back({i - 1, -num[i]});
        g[i - 1].push_back({i, 0});
    }

    vector<int> dist(N, -INF), cnt(N);
    vector<bool> st(N);
    queue<int> q;
    q.push(0);
    st[0] = true;
    dist[0] = 0;

    while (q.size())
    {
        int t = q.front();
        q.pop();
        st[t] = false;

        for (auto i : g[t])
        {
            int j = i.first;
            if(dist[j] < dist[t] + i.second)
            {
                dist[j] = dist[t] + i.second;
                cnt[j] = cnt[t] + 1;
                if(cnt[j] >= 25)
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

void solve()
{
    int n;
    for (int i = 1; i <= 24; i++)
        cin >> r[i];
    cin >> n;
    for (int i = 0; i <= 24;i++)
        num[i] = 0;
    for (int i = 0; i < n; i++)
    {
        int t;
        cin >> t;
        num[t + 1]++;
    }

    bool has_ans = false;
    for (int i = 0; i <= n; i++)
    {
        if(spfa(i))
        {
            has_ans = true;
            cout << i << '\n';
            break;
        }
    }
    if(!has_ans)
    {
        cout << "No Solution\n";
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    int T;
    cin>>T;
    while (T--)
    {
        solve();
    }
    return 0;
}