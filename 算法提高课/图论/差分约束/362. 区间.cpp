#include <iostream>
#include <vector>
#include <queue>

using namespace std;

using PII = pair<int, int>;
const int N = 5e4 + 10;

vector<vector<PII>> g(N);
vector<int> dist(N, -1e9);
vector<bool> st(N);

void spfa()
{
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
                if(!st[j])
                {
                    st[j] = true;
                    q.push(j);
                }
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    
    int m;
    cin >> m;

    for (int i = 1; i <= 50001; i++)
    {
        g[i - 1].push_back({i, 0});
        g[i].push_back({i - 1, -1});
    }

    while(m--)
    {
        int a, b, c;
        cin >> a >> b >> c;
        b++;
        g[a].push_back({b, c});
    }

    spfa();

    cout << dist[50001] << '\n';

    return 0;
}