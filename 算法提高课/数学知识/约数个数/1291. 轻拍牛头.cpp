#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <cstring>

using namespace std;
using i64 = long long;
using PII = pair<int,int>;

const int N = 1e5 + 10, M = 1e6 + 10;

int cnt[M];
int res[M];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);

    int n;

    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        cnt[a[i]]++;
    }

    for (int i = 1; i <= 1e6; i++)
        for (int j = i; j <= 1e6; j += i)
            res[j] += cnt[i];

    for (int i : a)
        cout << res[i] - 1 << '\n';

    return 0;
}