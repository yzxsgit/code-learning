#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e4 + 10, M = 5010;

int n, m, vol;
int v[N], w[N];
int p[N];
int f[N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m >> vol;

    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        cin >> v[i] >> w[i];
    }

    while (m -- )
    {
        int a, b;
        cin >> a >> b;
        int pa = find(a), pb = find(b);
        if (pa != pb)
        {
            v[pb] += v[pa];
            w[pb] += w[pa];
            p[pa] = pb;
        }
    }

    vector<PII> mp;
    for (int i = 1; i <= n; i++)
        if (i == p[i])
            mp.push_back({v[i],w[i]});
    for (auto [v,w] : mp)
        for (int j = vol; j >= v; j--)
            f[j] = max(f[j], f[j - v] + w);

    cout << f[vol] << '\n';

    return 0;
}