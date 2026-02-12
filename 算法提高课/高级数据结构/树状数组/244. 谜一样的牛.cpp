#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e5 + 10;

int tr[N];
int n;
int h[N];

int lowbit(int x)
{
    return x & -x;
}

void add(int x, int c)
{
    for (int i = x; i <= n; i += lowbit(i))
        tr[i] += c;
}

int sum(int x)
{
    int res = 0;
    for (int i = x; i; i -= lowbit(i))
        res += tr[i];
    return res;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    cin >> n;

    for (int i = 2; i <= n; i++)
        cin >> h[i];

    for (int i = 1; i <= n; i++)
        tr[i] = lowbit(i);

    vector<int> res;

    for (int i = n; i; i--)
    {
        int k = h[i] + 1;
        int l = 1, r = n;
        while (l < r)
        {
            int mid = l + r >> 1;
            if (sum(mid) >= k)
                r = mid;
            else
                l = mid + 1;
        }
        res.push_back(r);
        add(r, -1);
    }

    reverse(res.begin(), res.end());

    for (int ans : res)
        cout << ans << '\n';

    return 0;
}