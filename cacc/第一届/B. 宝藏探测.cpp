#include <iostream>

using namespace std;
const int N = 1e6 + 10;

int a[N];
int n, m;
int maxl[N], minl[N], maxr[N], minr[N];

int main()
{
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);

    minl[0] = minr[n + 1] = 1e9;
    for (int i = 1; i <= n - m - 1; i++)
    {
        minl[i] = min(a[i], minl[i - 1]);
        maxl[i] = max(a[i], maxl[i - 1]);
    }
    for (int i = n; i >= m + 1; i--)
    {
        minr[i] = min(a[i], minr[i + 1]);
        maxr[i] = max(a[i], maxr[i + 1]);
    }

    int res = 1e9;
    for (int i = 1; i <= n - m - 1; i++)
    {
        int mint = min(minl[i], minr[i + m + 1]), maxt = max(maxl[i], maxr[i + m + 1]);
        res = min(maxt - mint, res);
    }

    cout << res << "\n";

    return 0;
}