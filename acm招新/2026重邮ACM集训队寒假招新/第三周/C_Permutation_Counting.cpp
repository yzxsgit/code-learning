#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 2e5 + 10;

i64 a[N];
i64 n, k;

bool check(i64 mid)
{
    i64 p = mid / n;
    i64 q = mid % n;
    i64 cost = 0;

    for (int i = 0; i < q; i++)
    {
        if (a[i] < p + 1)
        {
            cost += (p + 1 - a[i]);
        }
        if (cost > k)
        {
            return false;
        }
    }

    for (int i = q; i < n; i++)
    {
        if (a[i] < p)
        {
            cost += (p - a[i]);
        }
        if (cost > k)
        {
            return false;
        }
    }

    return true;
}

bool cmp(i64 x,i64 y)
{
    return x > y;
}

void solve()
{
    cin >> n >> k;

    i64 sum_a = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum_a += a[i];
    }

    sort(a, a + n, cmp);

    i64 l = n - 1, r = sum_a + k;

    while (l < r)
    {
        i64 mid = l + r + 1 >> 1;
        if (check(mid))
        {
            l = mid;
        }
        else 
        {
            r = mid - 1;
        }
    }

    cout << max(0LL,r - n + 1) << '\n';
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int T;
    cin >> T;
    while (T--)
    {
        solve();
    }
    return 0;
}