#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 110;

vector<int> adj[N];
vector<int> din(N);
int n;
vector<int> res;

void topsort()
{
    queue<int> q;
    for (int i = 1; i <= n; i++)
        if(!din[i])
        {
            q.push(i);
        }
    
    while (q.size())
    {
        int t = q.front();
        q.pop();
        res.push_back(t);

        for (int v : adj[t])
        {
            din[v]--;
            if (!din[v]) q.push(v);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        int a;
        while (cin >> a && a)
        {
            adj[i].push_back(a);
            din[a]++;
        }
    }

    topsort();

    for (int ans : res)
        cout << ans << ' ';
    cout << '\n';

    return 0;
}