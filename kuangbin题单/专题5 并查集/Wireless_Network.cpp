#include <iostream>
#include <vector>
#include <cstdio> 

using namespace std;

typedef long long i64;
typedef pair<int, int> PII;

int p[1005]; 
bool st[1005];
PII a[1005];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

bool check(PII q1, PII q2, int d_limit_sq)
{
    i64 dx = (i64)q1.first - q2.first;
    i64 dy = (i64)q1.second - q2.second;
    return dx * dx + dy * dy <= (i64)d_limit_sq * d_limit_sq;
}

int main()
{
    int n, d;
    if (!(cin >> n >> d))
        return 0;

    for (int i = 1; i <= n; i++)
    {
        p[i] = i;
        cin >> a[i].first >> a[i].second;
    }

    char op[3];
    while (cin >> op)
    {
        if (op[0] == 'O')
        {
            int x;
            cin >> x;
            if (st[x])
                continue; 
            st[x] = true;
            for (int i = 1; i <= n; i++)
            {
                if (i != x && st[i] && check(a[i], a[x], d))
                {
                    int pa = find(x);
                    int pb = find(i);
                    if (pa != pb)
                        p[pb] = pa;
                }
            }
        }
        else if (op[0] == 'S')
        {
            int u, v;
            cin >> u >> v;
            if (find(u) == find(v))
                cout << "SUCCESS\n";
            else
                cout << "FAIL\n";
        }
    }
    return 0;
}