#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <bitset>

using namespace std;
using i64 = long long;
using PII = pair<int, int>;

const int N = 15;

bitset<N> g[N], f[N], ans[N];
int n, m;

int count(bitset<N> a[])
{
    int num = 0;
    for (int i = 0; i < m; i++)
        num += a[i].count();
    return num;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> m >> n;

    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            g[i][n - j - 1] = x;
        }
    }

    int minn = -1;

    for (int mask = 0; mask < (1 << n); mask++)
    {
        for (int i = 0; i < m; i++)
            f[i].reset();

        f[0] = bitset<N>(mask);

        for (int i = 1; i < m; i++)
        {
            f[i] = g[i - 1] ^ f[i - 1] ^ (f[i - 1] << 1) ^ (f[i - 1] >> 1);
            if (i - 2 >= 0)
                f[i] ^= f[i - 2];
            for (int k = n; k < N; k++)
                f[i][k] = 0;
        }

        bitset<N> last = g[m - 1] ^ f[m - 1] ^ (f[m - 1] << 1) ^ (f[m - 1] >> 1);
        if (m - 2 >= 0)
            last ^= f[m - 2];

        for (int k = n; k < N; k++)
            last[k] = 0;

        if (last.any())
            continue;

        int step = count(f);

        if (minn == -1 || step < minn)
        {
            minn = step;
            for (int i = 0; i < m; i++)
                ans[i] = f[i];
        }
    }

    if (minn == -1)
    {
        cout << "IMPOSSIBLE\n";
    }
    else
    {
        for (int i = 0; i < m; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (j)
                    cout << ' ';
                cout << ans[i][n - 1 - j];
            }
            cout << '\n';
        }
    }

    return 0;
}