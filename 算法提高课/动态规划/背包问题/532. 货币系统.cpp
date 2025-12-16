#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int N = 110, M = 3e4;
int a[N], f[M];
int n;
void solve()
{
    memset(f, 0, sizeof f);
    cin >> n;
    int m = 0;
    for (int i = 1; i <= n; i++)
        cin >> a[i], m = max(a[i], m);
    sort(a + 1, a + n + 1);

    int res = 0;
    f[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        if (f[a[i]] == 0)
            res++;
        for (int j = a[i]; j <= m; j++)
            f[j] += f[j - a[i]];
    }

    cout << res << "\n";
}

int main()
{
    
    int t;
    cin >> t;
    while (t--)
        solve();
}