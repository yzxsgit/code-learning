#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
const int N = 1e4 + 10;
struct Stone{
    int s, e, l;
} stone[N];
bool cmp(Stone a,Stone b)
{
    return a.s * b.l < b.s * a.l;
}
int f[N];
int solve()
{
    memset(f, 0, sizeof f);
    int n;
    cin >> n;
    int m = 0;
    for (int i = 0; i < n; i++)
    {
        int s, e, l;
        cin >> s >> e >> l;
        stone[i] = {s, e, l};
        m += s;
    }

    sort(stone, stone + n, cmp);

    for (int i = 0; i < n; i++)
    {
        int s = stone[i].s, e = stone[i].e, l = stone[i].l;
        for (int j = m; j >= s; j--)
            f[j] = max(f[j], f[j - s] + e - (j - s) * l);
    }

    int res = 0;
    for (int i = 0; i <= m; i++)
        res = max(res, f[i]);

    return res;
}

int main()
{
    int T;
    cin >> T;
    for (int i = 1; i <= T; i++)
        printf("Case #%d: %d\n", i, solve());

    return 0;
}