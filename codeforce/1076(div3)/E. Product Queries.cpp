#include <iostream>
#include <cstring>

using namespace std;

const int N = 3e5 + 10, INF = 0x3f3f3f3f;

int f[N];
int n;

void solve()
{
    memset(f, 0x3f, sizeof f);
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        int a;
        cin >> a;
        f[a] = 1;
    }

    for (int i = 1; i <= n; i++)
    {
        if (f[i] == INF)
        {
            int tmp = INF;
            for (int j = 2; j <= i / j; j++)
            {
                if (i % j == 0)
                    tmp = min(tmp, f[j] + f[i / j]);
            }
            f[i] = tmp;
        }
    }

    for (int i = 1; i <= n; i++)
        cout << (f[i] == 0x3f3f3f3f ? -1 : f[i]) << " ";
    cout << "\n";
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int T;
    cin >> T;

    while (T--)
    {
        solve();
    }

    return 0;
}