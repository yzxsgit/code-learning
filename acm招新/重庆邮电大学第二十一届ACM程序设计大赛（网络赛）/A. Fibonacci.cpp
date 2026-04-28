#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

#define int long long

using namespace std;
using PII = pair<int, int>;

const int N = 2;

int mod;
void mul(int c[], int a[], int b[][N])
{
    int temp[N] = {0};

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            temp[i] = (temp[i] + a[j] * b[j][i]) % mod;

    memcpy(c, temp, sizeof temp);
}

void mul(int c[][N], int a[][N], int b[][N])
{
    int temp[N][N];

    memset(temp, 0, sizeof temp);

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            for (int k = 0; k < N; k++)
                temp[i][j] = (temp[i][j] + a[i][k] * b[k][j]) % mod;

    memcpy(c, temp, sizeof temp);
}

void solve()
{
    int q;
    cin >> q >> mod;

    while (q--)
    {
        int f1[N] = {1, 0};
        int a[N][N] = {{1, 1}, {1, 0}};

        int t;
        cin >> t;
        while (t)
        {
            if (t & 1)
                mul(f1, f1, a);
            mul(a, a, a);
            t >>= 1;
        }
        cout << f1[1] << '\n';
    }
}

signed main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}