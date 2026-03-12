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
using PII = pair<int, int>;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;

    cin >> n >> k;

    vector<int> a(n);

    vector<int> q(n);
    int hh = 0, tt = -1;

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < n; i++)
    {
        while (hh <= tt && q[hh] < i - k + 1)
            hh++;
        while (hh <= tt && a[i] <= a[q[tt]])
            tt--;

        q[++tt] = i;

        if (i >= k - 1)
        {
            cout << a[q[hh]] << (i == n - 1 ? '\n' : ' ');
        }
    }

    hh = 0, tt = -1;
    for (int i = 0; i < n; i++)
    {
        while (hh <= tt && q[hh] < i - k + 1)
            hh++;
        while (hh <= tt && a[i] >= a[q[tt]])
            tt--;

        q[++tt] = i;

        if (i >= k - 1)
        {
            cout << a[q[hh]] << (i == n - 1 ? '\n' : ' ');
        }
    }

    return 0;
}