#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 2e5 + 10;

int h[N];
int a[N];

long long c[N];
int n;

int lowbit(int x)
{
    return x & -x;
}

void update(int x, long long val)
{
    for (; x <= n; x += lowbit(x))
    {
        c[x] = max(c[x], val);
    }
}

long long query(int x)
{
    long long res = 0;
    for (; x > 0; x -= lowbit(x))
    {
        res = max(res, c[x]);
    }
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    if (!(cin >> n))
        return 0;

    for (int i = 1; i <= n; i++)
    {
        cin >> h[i];
    }

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        long long maxx= query(h[i] - 1) + a[i];

        update(h[i], maxx);
    }

    cout << query(n) << endl;

    return 0;
}
