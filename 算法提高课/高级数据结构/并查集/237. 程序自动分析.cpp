#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <unordered_map>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 2e5 + 10;

int p[N];
int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

void solve()
{
    int m, n = 0;
    cin >> m;
    vector<PII> eq, uneq;
    unordered_map<int, int> mp;
    
    while (m--)
    {
        int a, b, t;
        cin >> a >> b >> t;
        if (!mp.count(a)) mp[a] = n++;
        if (!mp.count(b)) mp[b] = n++;
        int ma = mp[a], mb = mp[b];

        if (t == 1) eq.push_back({ma, mb});
        else uneq.push_back({ma, mb});
    }
    for (int i = 0; i < n; i++)
        p[i] = i;

    for (auto [a, b] : eq)
    {
        int pa = find(a), pb = find(b);
        if (pa != pb) p[pb] = pa;
    }

    bool res = true;
    for (auto [a, b] : uneq)
    {
        int pa = find(a), pb = find(b);
        if (pa == pb)
        {
            res = false;
            break;
        }   
    }

    cout << (res ? "YES\n" : "NO\n");
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