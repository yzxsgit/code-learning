#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 3e4 + 10;

int n, m;
int p[N], s[N], d[N];

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

    cin >> m;
    for (int i = 1; i < N; i++)
    {
        p[i] = i;
        s[i] = 1;
        d[i] = 0;
    }

    while (m--)
    {
        char op[2];
        int a, b;
        cin >> op >> a >> b;
        if (op[0] == 'M')
        {
            int pa = find(a), pb = find(b);
            if (pa != pb)
            {
                d[pa] = s[pb];
                s[pb] += s[pa];
                p[pa] = pb;
            }
        }
        else 
        {
            int pa = find(a), pb = find(b);
            if (pa != pb) cout << -1 << '\n';
            else cout << max(0, abs(d[a] - d[b]) - 1) << '\n';
        }
    }

    return 0;
}