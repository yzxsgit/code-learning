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
    for (int i = 0; i < n; i++)
        cin >> a[i];

    vector<int> q(n);

    int hh = 0, tt = -1;

    for (int i = 0; i < n; i++)
    {
        while (hh <= tt && q[hh] < i - k)
            hh++;
        while (hh <= tt && a[i] <= a[q[tt]])
            tt--;

        cout << (i == 0 ? 0 : a[q[hh]]) << '\n';

        q[++tt] = i;
    }
    return 0;
}