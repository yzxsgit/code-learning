#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 210;

bool g[N][N];
int n, m;
int match[N];
bool st[N];

void floyd()
{
    for (int k = 1; k <= n; k++)
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                g[i][j] |= g[i][k] & g[k][j];
}

bool find(int x)
{
    for (int i = 1; i <= n; i++)
    {
        if(g[x][i] && !st[i])
        {
            st[i] = true;
            if(match[i] == 0 || find(match[i]))
            {
                match[i] = x;
                return true;
            }
        }
    }

    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0),cout.tie(0);

    cin >> n >> m;

    while (m--)
    {
        int a, b;
        cin >> a >> b;
        g[a][b] = true;
    }

    floyd();

    int res = 0;

    for (int i = 1; i <= n; i++)
    {
        memset(st, 0, sizeof st);
        if (find(i))
            res++;
    }

    cout << n - res << '\n';

    return 0;
}