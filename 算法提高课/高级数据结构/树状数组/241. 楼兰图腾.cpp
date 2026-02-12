#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 2e5 + 10;

int n;
int tr[N];
int great[N], low[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i)) tr[i] += c;
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i)) res += tr[i];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i <= n; i++)
    {
        int y = a[i];
        great[i] = sum(n) - sum(y);
        low[i] = sum(y - 1);
        add(y, 1);
    }

    memset(tr, 0, sizeof tr);
    i64 res1 = 0, res2 = 0;
    for (int i = n; i; i--)
    {
        int y = a[i];
        res1 += great[i] * (i64)(sum(n) - sum(y));
        res2 += low[i] * (i64)(sum(y - 1));
        add(y, 1);
    }

    cout << res1 << " " << res2 << '\n';

    return 0;
}