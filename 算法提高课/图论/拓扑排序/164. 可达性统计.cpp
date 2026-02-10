#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <bitset>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 3e4 + 10;

vector<int> adj[N], din(N), res;
bitset<N> f[N];
int n, m;

void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if (!din[i])
            q.push(i);

    while (q.size())
    {
        int t = q.front();
        q.pop();
        res.push_back(t);

        for (int v : adj[t])
        {
            din[v]--;
            if (!din[v])
                q.push(v);
        }
    }
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
        adj[a].push_back(b);
        din[b]++;
    }

    topsort();

    reverse(res.begin(), res.end());

    for (int i : res)
    {
        f[i][i] = 1;
        for (int j : adj[i])
            f[i] |= f[j];
    }

    for (int i = 1; i <= n; i++)
        cout << f[i].count() << '\n';
    
    return 0;
}