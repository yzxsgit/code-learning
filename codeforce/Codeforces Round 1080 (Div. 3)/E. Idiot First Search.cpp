#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 3e5 + 10, mod = 1e9 + 7;

struct Node
{
    int l, r;
    int l_cnt, r_cnt;
    int res;
}tr[N];

int dfs(int u)
{
    if (tr[u].l)
        tr[u].l_cnt = dfs(tr[u].l);
    if (tr[u].r)
        tr[u].r_cnt = dfs(tr[u].r);

    return tr[u].l_cnt + tr[u].r_cnt + 1;
}

void bfs()
{
    queue<int> q;
    q.push(1);

    while (q.size())
    {
        int u = q.front();
        q.pop();

        int l = tr[u].l, r = tr[u].r;
        tr[u].res = (i64)(tr[u].res + tr[u].l_cnt * 2 + tr[u].r_cnt * 2 + 1) % mod;

        if (l)
        {
            tr[l].res = tr[u].res;
            q.push(l);
        }
        if (r)
        {
            tr[r].res = tr[u].res;
            q.push(r);
        }
    }
}

void solve()
{
    int n;
    cin >> n;
    
    tr[0].l = 1;
    for (int i = 1; i <= n; i++)
    {
        cin >> tr[i].l >> tr[i].r;
        tr[i].l_cnt = 0;
        tr[i].r_cnt = 0;
        tr[i].res = 0;
    }
    dfs(0);
    bfs();
    for (int i = 1; i <= n; i++)
        cout << tr[i].res << ' ';
    cout << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}