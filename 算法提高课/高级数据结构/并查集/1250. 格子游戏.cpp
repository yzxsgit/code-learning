#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 210, M = 24010;

int n, m;
int p[N * N];

int find(int x)
{
    if (p[x] != x)
        p[x] = find(p[x]);
    return p[x];
}

int get(int x, int y)
{
    return x * n + y;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n >> m;

    for (int i = 0; i < n * n; i++)
        p[i] = i;

    int res = -1;
    for (int i = 1; i <= m; i++)
    {
        int x, y;
        char op[2];
        cin >> x >> y >> op;
        int a, b;
        if (op[0] == 'D')
        {
            a = get(x - 1, y - 1);
            b = get(x, y - 1);
        }
        else 
        {
            a = get(x - 1, y - 1);
            b = get(x - 1, y);
        }

        a = find(a), b = find(b);
        if (a == b)
        {
            res = i;
            break;
        }
        else 
        {
            p[b] = a;
        }
    }

    if (~res)
        cout << res << '\n';
    else
        cout << "draw\n";

    return 0;
}