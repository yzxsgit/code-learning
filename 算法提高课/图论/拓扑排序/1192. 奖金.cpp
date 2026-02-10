#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e5 + 10;

vector<bool> st(N, false);
vector<int> adj[N], din(N), money(N, 100);
int n, m;
i64 res;

bool topsort()
{
    int num = 0;
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if(!din[i])
            q.push(i);

    while (q.size())
    {
        int t = q.front();
        q.pop();
        num++;
        if (st[t]) return false;
        st[t] = true;
        res += money[t];

        for (int v : adj[t])
        {
            din[v]--;
            money[v] = max(money[v], money[t] + 1);
            if (!din[v]) q.push(v);
        }
    }

    return num == n;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        adj[b].push_back(a);
        din[a]++;
    }

    if (topsort()) cout << res << '\n';
    else cout << "Poor Xed\n";

    return 0;
}