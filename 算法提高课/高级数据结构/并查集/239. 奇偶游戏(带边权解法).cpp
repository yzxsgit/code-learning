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

const int N = 2e4 + 10;

int n, m;
int p[N], d[N];
int idx = 0;
unordered_map<int, int> S;

int get(int x)
{
    if (!S.count(x)) S[x] = ++idx;
    return S[x];
}

int find(int x)
{
    if (p[x] != x)
    {
        int root = find(p[x]);
        d[x] += d[p[x]];
        p[x] = root;
    }
    return p[x];
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;
    for (int i = 0; i < N; i++)
        p[i] = i;

    int res = m;
    for (int i = 1; i <= m; i++)
    {
        int a, b;
        string op;
        cin >> a >> b >> op;
        a = get(a - 1), b = get(b);
        int t = 0;
        if (op == "odd") t = 1;

        int pa = find(a), pb = find(b);
        if (pa == pb)
        {
            if (((d[a] + d[b]) % 2 + 2) % 2 != t)
            {
                res = i - 1;
                break;
            }
        }
        else 
        {
            p[pa] = pb;
            d[pa] = d[a] ^ d[b] ^ t;
        }
    }

    cout << res << '\n';

    return 0;
}